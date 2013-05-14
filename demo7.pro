#-------------------------------------------------
#
# Project created by QtCreator 2013-05-06T20:06:26
#
#-------------------------------------------------

QT       += core gui
QT       += webkit
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo7
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
        userfunction.cpp \
        login.cpp \
        clientSocket.cpp

HEADERS  += mainwindow.h \
        userfunction.h \
        login.h \
        ui_clientSocket.h \
        clientSocket.h

RESOURCES += \
    filePNG.qrc
