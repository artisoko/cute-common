#-------------------------------------------------
#
# Project created by QtCreator 2013-06-23T13:30:43
#
#-------------------------------------------------

TARGET = hexgrid
TEMPLATE = lib

DEFINES += HEXGRID_LIBRARY

SOURCES += hexgrid.cpp

HEADERS += hexgrid.h\
        hexgrid_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
