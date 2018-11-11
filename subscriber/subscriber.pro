QT += core dbus
QT -= gui

TARGET = subscriber
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    subscriber.cpp

HEADERS += \
    subscriber.h

