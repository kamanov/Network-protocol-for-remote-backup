#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T21:12:54
#
#-------------------------------------------------
include(../common/common.pri)


CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

TARGET = server
SOURCES += main.cpp


INCLUDEPATH += "$$top_srcdir/common"
LIBS += -L$${LIBS_PATH} -lutil

DESTDIR = "$$top_srcdir/output"


