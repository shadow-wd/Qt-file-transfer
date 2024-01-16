HEADERS += \
    mainwindow.h

SOURCES += \
    mainwindow.cpp \
    server.cpp

FORMS += \
    mainwindow.ui

DEFINES += QT_DEPRECATED_WARNINGS
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

