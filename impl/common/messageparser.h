#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include <event2/buffer.h>

class MessageParser
{
public:
    MessageParser();
    void add_data(struct evbuffer* buf);
private:
    struct evbuffer* m_buffer;
};

#endif // MESSAGEPARSER_H
