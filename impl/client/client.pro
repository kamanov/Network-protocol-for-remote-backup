#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T19:56:33
#
#-------------------------------------------------
include(../common/common.pri)

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

TARGET = client
SOURCES += \
    networkcontroller.cpp \
    clientconfiguration.cpp \
    test.cpp \
    main.cpp


INCLUDEPATH += "$$top_srcdir/common"
LIBS += -L$${LIBS_PATH} -lutil

HEADERS += \
    networkcontroller.h \
    clientconfiguration.h

DESTDIR = "$$top_srcdir/output"

