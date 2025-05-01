QT += core gui sql network printsupport charts widgets serialport


CONFIG += c++11

SOURCES += \
    arduino.cpp \
    main.cpp \
    mainwindow.cpp \
    events.cpp \
    connection.cpp \
    statistique.cpp

HEADERS += \
    arduino.h \
    mainwindow.h \
    events.h \
    connection.h \
    statistique.h

FORMS += \
    mainwindow.ui \

RESOURCES += \
    Ressources.qrc

win32:!debug: CONFIG -= console
