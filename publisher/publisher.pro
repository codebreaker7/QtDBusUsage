QT += core dbus
QT -= gui

TARGET = publisher
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    publisher.cpp

HEADERS += \
    publisher.h
