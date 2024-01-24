

DEFINES += QT_DEPRECATED_WARNINGS
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    server.h

SOURCES += \
    main.cpp \
    server.cpp

FORMS += \
    server.ui

