#include <arpa/inet.h>
#include <iostream>
#include "deserializer.h"
#include "msgpack.hpp"
#include "messages.h"

Deserializer::Deserializer(DeserializerDelegate *delegate)
    : m_delegate(delegate)
{
    assert(delegate != nullptr && "delegate should not be null");
}

uint32_t Deserializer::deserialize(const char* data, size_t len)
{
    if (len < sizeof(uint32_t)) {
        parse_error("insufficient data");
        return 0;
    }
    size_t offset = 0;
    uint32_t msg_length = parse_length(data, offset);
    uint32_t total_length = msg_length + offset;
    if (len < total_length) {
        parse_error("insufficient data");
        return 0;
    }

    msgpack::unpacker pac;
    pac.reserve_buffer(msg_length);
    memcpy(pac.buffer(), data + offset, msg_length);
    pac.buffer_consumed(msg_length);
    msgpack::unpacked result;
    MESSAGE_TYPE msg_type;
    //parse message type
    if (pac.next(result)) {
        msgpack::object obj = result.get();
        try {
            msg_type = (MESSAGE_TYPE)obj.as<uint32_t>();
        } catch (msgpack::type_error& e) {
            std::cerr << "parse message error : " << e.what() << std::endl;
            parse_error(e.what());
            return total_length;
        }
    } else {
        parse_error("parse message type error");
        return total_length;
    }

    //parse message
    if (pac.next(result)) {
        msgpack::object obj = result.get();
        try {
            switch (msg_type) {
            case M_ACK:
                m_delegate->onAckMessageReceived(obj.as<AckMessage>());
                break;
            case M_DATA:
                m_delegate->onDataMessageReceived(obj.as<DataMessage>());
                break;
            default: return total_length;
                break;
            }
        } catch (msgpack::type_error& e) {
            std::cerr << "parse message error : " << e.what() << std::endl;
            parse_error(e.what());
            return total_length;
        }
    } else {
        parse_error("parse message body error");
    }
    return total_length;
}

void Deserializer::parse_error(const std::string& what) {
    m_delegate->onParseErrorOccured(what);
}

uint32_t Deserializer::parse_length(const char* data, size_t& offset)
{
    uint32_t length = 0;
    memcpy(&length, data, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    return ntohl(length);
}
