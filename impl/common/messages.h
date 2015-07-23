#ifndef MESSAGES_H
#define MESSAGES_H

#include <stdint.h>
#include <memory>
#include "serializer.h"
#include "msgpack.hpp"

enum MESSAGE_TYPE : uint32_t {
    M_ACK = 1,
    M_DATA,
    M_HAS_BLOCK_REQUEST,
    M_HAS_BLOCK_RESPONSE,
    M_SESSION_START,
    M_SESSION_CONFIRM,
    FINAL_MESSAGE_TYPE_ENTRY
};

struct evbuffer;

struct Message {
    MESSAGE_TYPE type;
    Message(MESSAGE_TYPE t) : type(t) {}
    virtual void serialize(evbuffer* out_buffer) = 0;
};

struct AckMessage : public Message {
    AckMessage() : Message(M_ACK) {}
    uint64_t ack_id;
    void serialize(evbuffer* out_buffer) {
        return Serializer::serialize(*this, out_buffer);
    }

    MSGPACK_DEFINE(ack_id)
};

struct DataMessage : public Message {
    DataMessage() : Message(M_DATA) {}
    uint64_t id;
    uint32_t length; // data length
    std::shared_ptr<char> data;

    template <typename Packer>
    void msgpack_pack(Packer& pk) const {
      pk.pack_array(2);

      pk.pack_int64(id);
      pk.pack_bin(length);
      pk.pack_bin_body(data.get(), length);
    }

     void msgpack_unpack(msgpack::object const& o) {
      if(o.type != msgpack::type::ARRAY) { throw msgpack::type_error(); }

      const size_t size = o.via.array.size;

      if(size < 2) { throw msgpack::type_error(); }
      id = o.via.array.ptr[0].via.u64;

      msgpack::object_bin bin = o.via.array.ptr[1].via.bin;
      length = bin.size;
      char* new_data =  new char[length];
      memcpy(new_data, bin.ptr, bin.size);
      data = std::shared_ptr<char>(new_data);
    }

    template <typename MSGPACK_OBJECT>
    void msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const {
    }

    void serialize(evbuffer* out_buffer) {
        return Serializer::serialize(*this, out_buffer);
    }
};


#endif // MESSAGES_H
