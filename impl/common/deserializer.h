#ifndef DESERIALIZER_H
#define DESERIALIZER_H
#include <stdint.h>
#include "messages.h"
#include "event2/buffer.h"

class DeserializerDelegate;

class Deserializer
{
public:
    Deserializer(DeserializerDelegate* delegate);
    uint32_t deserialize(const char* data, size_t len);

private:
    uint32_t parse_length(const char* data, size_t& offset);
    void parse_error(const std::string& what);
    DeserializerDelegate* m_delegate;

};

class DeserializerDelegate {
public:
    virtual void onAckMessageReceived(AckMessage msg) = 0;
    virtual void onDataMessageReceived(DataMessage msg) = 0;
    virtual void onParseErrorOccured(const std::string& what) = 0;
};

#endif // DESERIALIZER_H
