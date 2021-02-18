
QT        +=  xml 
                    
CONFIG += c++17

INCLUDEPATH += . ..
WARNINGS += -Wall
TARGET = db
TEMPLATE = lib
#CONFIG += staticlib


HEADERS += *.h
SOURCES += *.cpp

CONFIG(debug, debug|release) {
    DESTDIR = ../main/debug
} else {
    DESTDIR = ../main/release
}

#use dynamic lib for util
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../main/release/ -lutil
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../main/debug/ -lutil
else:unix: LIBS += -L$$OUT_PWD/../main/ -lutil

INCLUDEPATH += $$PWD/../util
DEPENDPATH += $$PWD/../util


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target