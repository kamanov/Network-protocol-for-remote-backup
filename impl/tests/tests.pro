include(../common/common.pri)

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

TARGET = test

INCLUDEPATH += "$$top_srcdir"

LIBS += -L$${LIBS_PATH} -lutil

INCLUDEPATH += "$$top_srcdir/bandit-1.1.4"

SOURCES += \
    main.cpp \
    serialization_test.cpp \
    configuration_test.cpp \
    ../client/clientconfiguration.cpp


DESTDIR = "$$top_srcdir/output"
