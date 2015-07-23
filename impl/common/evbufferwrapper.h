#ifndef EVBUFFERWRAPPER_H
#define EVBUFFERWRAPPER_H

#include "event2/buffer.h"

class EVBufferWrapper
{
public:
    EVBufferWrapper(evbuffer* buffer) : m_buffer(buffer) {}
    void write(const char* data, size_t size);

private:
    struct evbuffer* m_buffer;
};

#endif // EVBUFFERWRAPPER_H
