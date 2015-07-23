#include "messageparser.h"
#include "serializer.h"
enum PARSER_STATE {
    P_IDLE,
    P_PARSING
};

MessageParser::MessageParser()
{
}

void MessageParser::add_data(evbuffer *buf)
{
    evbuffer_add_buffer(m_buffer, buf);
}

