#include <bandit/bandit.h>
#include <functional>
#include "common/serializer.h"
#include "common/deserializer.h"
#include "common/messages.h"

typedef std::function<void (Message*)> MessageCallback;
typedef std::function<void (void)> ErrorCallback;
class TestDeserializerDelegate : public DeserializerDelegate {
public:
    MessageCallback messageCallback;
    ErrorCallback errorCallback;

    virtual void onAckMessageReceived(AckMessage msg) {
        messageCallback(&msg);
    }

    virtual void onDataMessageReceived(DataMessage msg) {
        messageCallback(&msg);
    }

    virtual void onParseErrorOccured(const std::string& what) {
        errorCallback();
    }


};

using namespace bandit;

go_bandit([](){
    describe("serialization:", [](){

      void (*test_msg)(Message*, MessageCallback) = [](Message* msg, MessageCallback msgCallback) {
          evbuffer* buffer = evbuffer_new();
          msg->serialize(buffer);
          size_t data_size = evbuffer_get_length(buffer);
          AssertThat(data_size, IsGreaterThan(0));

          TestDeserializerDelegate delegate;

          delegate.messageCallback = msgCallback;

          ErrorCallback errorCallback = []() {
              AssertThat(false, Equals(true));
          };
          delegate.errorCallback = errorCallback;

          Deserializer deserializer(&delegate);

          char* data = new char[data_size];
          evbuffer_remove(buffer, data, data_size);

          uint32_t bytes_parsed = deserializer.deserialize(data, data_size);
          AssertThat(bytes_parsed, Equals(data_size));
          evbuffer_free(buffer);
      };

      it("should serialize DataMessage", [&](){
          DataMessage msg;
          msg.id = 1;
          msg.length = 256;
          msg.data = std::shared_ptr<char>(new char[msg.length]);

          MessageCallback msgCallback = [&](Message* message) {
            AssertThat(message->type, Equals(M_DATA));
            DataMessage* res_msg = (DataMessage*)message;
            AssertThat(res_msg->id, Equals(msg.id));
            AssertThat(res_msg->length, Equals(msg.length));
            AssertThat(memcmp(res_msg->data.get(), msg.data.get(), msg.length), Equals(0));
          };
          test_msg(&msg, msgCallback);
      });

      it("should serialize AckMessage", [&](){
          AckMessage msg;
          msg.ack_id = 1;

          MessageCallback msgCallback = [&](Message* message) {
            AssertThat(message->type, Equals(M_ACK));
            AckMessage* res_msg = (AckMessage*)message;
            AssertThat(res_msg->ack_id, Equals(msg.ack_id));
          };
          test_msg(&msg, msgCallback);
      });

      it("should not deserialize data with insufficient length", [&](){
          AckMessage msg;
          msg.ack_id = 1;

          evbuffer* buffer = evbuffer_new();
          msg.serialize(buffer);
          char c;
          evbuffer_remove(buffer, &c, 1);

          size_t data_size = evbuffer_get_length(buffer);
          AssertThat(data_size, IsGreaterThan(0));

          TestDeserializerDelegate delegate;

          bool flag = false;
          ErrorCallback errorCallback = [&]() {
              flag = true;
          };

          MessageCallback msgCallback = [&](Message* message) {
            AssertThat(false, Equals(true));
          };
          delegate.messageCallback = msgCallback;
          delegate.errorCallback = errorCallback;

          Deserializer deserializer(&delegate);

          char* data = new char[data_size];
          evbuffer_remove(buffer, data, data_size);

          uint32_t bytes_parsed = deserializer.deserialize(data, data_size);
          AssertThat(flag, Equals(true));
          AssertThat(bytes_parsed, Equals(0));


      });
    });
});
