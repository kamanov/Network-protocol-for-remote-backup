QT       -= gui
QT       -= core

CONFIG += C++11

LIBS_PATH = "$$top_srcdir/libs/"

INCLUDEPATH += "/usr/local/include"
LIBS += -L"/usr/local/lib" -levent

INCLUDEPATH += "$$top_srcdir/msgpack-c/include"

INCLUDEPATH += "$$top_srcdir/libconfig-1.4.9/lib"
LIBS += -L$${LIBS_PATH} -lconfig++



