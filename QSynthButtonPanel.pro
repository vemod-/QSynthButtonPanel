QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SynthButtonPanel
TEMPLATE = app

include(qsynthbuttonpanel.pri)

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

SOURCES += \
    mainwindow.cpp \
    main.cpp
