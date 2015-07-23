#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <functional>
#include <arpa/inet.h>
#include "msgpack.hpp"
#include "evbufferwrapper.h"
struct evbuffer;

class Serializer
{
public:
    template<typename T>
    static void serialize(T& msg, evbuffer* out_buffer);

private:
    typedef msgpack::packer<EVBufferWrapper> MessagePacker;
    template<typename T>
    static void serialize_message(T& msg, MessagePacker& pk);
    static void serialize_length(evbuffer* out_buffer, uint32_t length) {
        uint32_t nlength = htonl(length);
        evbuffer_add(out_buffer, &nlength, sizeof(uint32_t));
    }

};

template<typename T>
void Serializer::serialize(T& msg, evbuffer* out_buffer) {
    assert(out_buffer != nullptr && "out buffer should be valid");
    evbuffer* msg_buffer = evbuffer_new();
    EVBufferWrapper bufferWrapper(msg_buffer);
    MessagePacker pk(&bufferWrapper);
    pk.pack_int32(msg.type);
    pk.pack(msg);
    serialize_length(out_buffer, evbuffer_get_length(msg_buffer));
    evbuffer_add_buffer(out_buffer, msg_buffer);
    evbuffer_free(msg_buffer);
}

#endif // SERIALIZER_H
