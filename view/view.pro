QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += . ..
WARNINGS += -Wall
TARGET = view
TEMPLATE = lib
CONFIG += staticlib


HEADERS += *.h
SOURCES += *.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#CONFIG(debug, debug|release) {
#    DESTDIR = ../main/debug
#} else {
#    DESTDIR = ../main/release
#}


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../util/release/ -llibutil
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../util/debug/ -llibutil
else:unix: LIBS += -L$$OUT_PWD/../util/ -llibutil


INCLUDEPATH += $$PWD/../util
DEPENDPATH += $$PWD/../util

