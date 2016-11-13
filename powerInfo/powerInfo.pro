#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T12:19:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = powerInfo
TEMPLATE = app


SOURCES += main.cpp\
        powertable.cpp \
    tablemodel.cpp

HEADERS  += powertable.h \
    tablemodel.h

RESOURCES += \
    image.qrc
