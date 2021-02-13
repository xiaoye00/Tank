QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += . ..
WARNINGS += -Wall
TARGET = view
TEMPLATE = lib


HEADERS += *.h
SOURCES += *.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG(debug, debug|release) {
    DESTDIR = ../main/debug
} else {
    DESTDIR = ../main/release
}

