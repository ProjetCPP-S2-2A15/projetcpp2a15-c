QT += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console
win32: CONFIG += console

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    events.cpp

HEADERS += \
    mainwindow.h \
    connection.h \
    events.h


FORMS += \
    mainwindow.ui
RESOURCES += \
        Ressources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


