#include "evbufferwrapper.h"


void EVBufferWrapper::write(const char *data, size_t size)
{
    evbuffer_add(m_buffer, data, size);
}
