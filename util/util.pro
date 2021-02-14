
QT        +=  xml 
                    
CONFIG += c++17

INCLUDEPATH += . ..
WARNINGS += -Wall
TARGET = util
TEMPLATE = lib
#CONFIG += staticlib


HEADERS += *.h
SOURCES += *.cpp

CONFIG(debug, debug|release) {
    DESTDIR = ../main/debug
} else {
    DESTDIR = ../main/release
}


DEFINES -= QT_NO_DEBUG_OUTPUT


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target