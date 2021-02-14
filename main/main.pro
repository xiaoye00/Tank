QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET=Tank
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += $$files("*.cpp", true)
HEADERS += $$files("*.h", true)



DEFINES -= QT_NO_DEBUG_OUTPUT



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#use static lib
#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../util/release/ -llibutil
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../util/debug/ -llibutil
#else:unix: LIBS += -L$$OUT_PWD/../util/ -llibutil

#use dynamic lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../main/release/ -lutil
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../main/debug/ -lutil
else:unix: LIBS += -L$$OUT_PWD/../main/ -lutil


INCLUDEPATH += $$PWD/../util
DEPENDPATH += $$PWD/../util


