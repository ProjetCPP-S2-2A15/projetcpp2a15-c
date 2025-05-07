#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT += core gui sql
QT += network
QT += charts
QT += serialport
QT += printsupport
QT += core gui sql network charts serialport printsupport quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    arduinointerface.cpp \
    arduinowidget.cpp \
    employee1.cpp \
    events.cpp \
    local.cpp \
    loginwindow.cpp \
    mailer.cpp \
    main.cpp \
    mainevent.cpp \
    mainloclac.cpp \
    mainmaintenance.cpp \
    mainservice.cpp \
    maintenance.cpp \
    mainwindow.cpp \
    connection.cpp \
    notificationpanel.cpp \
    registerwindow.cpp \
    services.cpp \
    statistique.cpp \
    mimetext.cpp \
    statistiqueev.cpp \
    chatbotmanager.cpp \
    emailaddress.cpp \
    localchat.cpp \
    locataire.cpp \
    mimeattachment.cpp \
    mimebase64encoder.cpp \
    mimebase64formatter.cpp \
    mimecontentencoder.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimeqpencoder.cpp \
    mimeqpformatter.cpp \
    quotedprintable.cpp \
    smtpclient.cpp

HEADERS += \
    arduino.h \
    arduinointerface.h \
    arduinowidget.h \
    employee1.h \
    events.h \
    local.h \
    loginwindow.h \
    mailer.h \
    mainevent.h \
    mainloclac.h \
    mainmaintenance.h \
    mainservice.h \
    maintenance.h \
    mainwindow.h \
    connection.h \
    notificationpanel.h \
    registerwindow.h \
    services.h \
    statistique.h \
    statistiqueev.h \
    mimetext.h \
    chatbotmanager.h \
    emailaddress.h \
    localchat.h \
    locataire.h \
    mimeattachment.h \
    mimebase64encoder.h \
    mimebase64formatter.h \
    mimecontentencoder.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimeqpencoder.h \
    mimeqpformatter.h \
    quotedprintable.h \
    smtpclient.h

FORMS += \
    mainevent.ui \
    mainloclac.ui \
    mainmaintenance.ui \
    mainservice.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    qml.qrc \
    ressource.qrc
