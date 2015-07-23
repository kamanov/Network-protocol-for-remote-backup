#include "msgpack.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include <stdint.h>

enum MESSAGE_TYPE  {
    M_FLUSH = 1,
    M_DATA,
    M_HAS_BLOCK_REQUEST,
    M_HAS_BLOCK_RESPONSE,
    M_SESSION_START,
    M_SESSION_CONFIRM,
    FINAL_MESSAGE_TYPE_ENTRY
};


struct Message {
    MESSAGE_TYPE type;
    Message(MESSAGE_TYPE t) : type(t) {}
};

struct AckMessage : public Message {
    AckMessage() : Message(M_FLUSH) {}
};

struct DataMessage : public Message {
    DataMessage() : Message(M_DATA) {}
    uint64_t id;
    uint32_t length; // data length
    char* data;

    template <typename Packer>
    void msgpack_pack(Packer& pk) const {
      // make array of two elements, by the number of class fields
      pk.pack_array(2);

      pk.pack_int64(id);
      pk.pack_bin(length);
      pk.pack_bin_body(data, length);
    }

     void msgpack_unpack(msgpack::object const& o) {
      // check if received structure is an array
      if(o.type != msgpack::type::ARRAY) { throw msgpack::type_error(); }

      const size_t size = o.via.array.size;

      // sanity check
      if(size <= 0) return;
      // extract value of first array entry to a class field
      id = o.via.array.ptr[0].via.u64;

      // sanity check
      if(size <= 1) return;
      // extract value of second array entry which is array itself:
      msgpack::object_bin s = o.via.array.ptr[1].via.bin;
      length = s.size;
      data = new char[length];
      memcpy(data, s.ptr, s.size);
    }

    // destination of this function is unknown - i've never ran into scenary
    // what it was called. some explaination/documentation needed.
    template <typename MSGPACK_OBJECT>
    void msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const {

    }

};



int main(void) {
    std::stringstream bufferWrapper;
    msgpack::packer<std::stringstream> pk(&bufferWrapper);
    DataMessage msg;
    int a = 3;
    char a1[2] = {(char)100, (char)2};
    char *c = "test";
    msg.length = 4;
    msg.id = 3;
    msg.type = M_DATA;
    msg.data = a1;
    //std::cout << (int)msg.data[0] << std::endl;
    pk.pack(msg);

    msgpack::unpacker pac;



    msgpack::unpacked unp;
    msgpack::unpack(unp, bufferWrapper.str().data(), bufferWrapper.str().size() - 4);
    /*DataMessage msg111 = unp.get().as<DataMessage>();
        std::cout << msg111.id << std::endl;
        std::cout << msg111.length << std::endl;
        std::cout << (int)msg111.data[0] << std::endl;*/
        /*
        while(pac.next(&result)) {
            i++;
       //         // do some with the object with the zone.
                msgpack::object obj = result.get();
                std::cout << obj << std::endl;
                if (obj.type == MSGPACK_OBJECT_BIN) {

                    const char* zzz = obj.via.bin.ptr;
                    std::cout << (int)zzz[0] << std::endl;
                }


      //         std::auto_ptr<msgpack:zone> z = result.zone();
       //         on_message(obj, z);
       //
       //         //// boost::shared_ptr is also usable:
       //         // boost::shared_ptr<zone> life(z.release());
       //         // on_message(result.get(), life);
       //     }
       //
       //     // 5.
       //     if(pac.message_size() > 10*1024*1024) {
       //         throw std::runtime_error("message is too large");
       //     }
       }
       //
       */

    return 0;
    
}
