
TARGET = client

HEADERS += \
    client.h

SOURCES += \
    client.cpp \
    main.cpp

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

FORMS += \
    client.ui \
    client.ui
