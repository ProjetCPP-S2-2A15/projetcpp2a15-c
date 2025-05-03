QT       += core gui sql
QT += network

QT += core gui network
QT += charts
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Pour émettre des avertissements sur les API obsolètes
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    arduino.cpp \
    chatbotmanager.cpp \
    connection.cpp \
    emailaddress.cpp \
    localchat.cpp \
    locataire.cpp \
    main.cpp \
    mainwindow.cpp \
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
    mimetext.cpp \
    quotedprintable.cpp \
    smtpclient.cpp

HEADERS += \
    arduino.h \
    chatbotmanager.h \
    connection.h \
    emailaddress.h \
    localchat.h \
    locataire.h \
    mainwindow.h \
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
    mimetext.h \
    quotedprintable.h \
    smtpclient.h \
    smtpmime_global.h

FORMS += \
    mainwindow.ui

# Règles de déploiement par défaut
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc

