include(common.pri)

TARGET = util
TEMPLATE = lib

DESTDIR = "$$top_srcdir/libs"

OTHER_FILES += \
    common.pri

HEADERS += \
    messages.h \
    util.h \
    serializer.h \
    deserializer.h \
    messageparser.h \
    evbufferwrapper.h

SOURCES += \
    deserializer.cpp \
    messageparser.cpp \
    evbufferwrapper.cpp
