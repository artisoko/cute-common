#-------------------------------------------------
#
# Project created by QtCreator 2013-06-22T01:08:26
#
#-------------------------------------------------

QT       += widgets opengl

TARGET = gl-viewer-lib
TEMPLATE = lib

DEFINES += GLVIEWERLIB_LIBRARY

SOURCES += glviewerlib.cpp \
    glwindow.cpp \
    glwidget.cpp

HEADERS += glviewerlib.h\
        gl-viewer-lib_global.h \
    glwindow.h \
    drawable.h \
    glwidget.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
