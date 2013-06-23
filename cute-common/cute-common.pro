#-------------------------------------------------
#
# Project created by QtCreator 2013-06-23T14:32:58
#
#-------------------------------------------------

TARGET = cute-common
TEMPLATE = lib

DEFINES += CUTECOMMON_LIBRARY

SOURCES += cutecommon.cpp

HEADERS += cutecommon.h\
        cute-common_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
