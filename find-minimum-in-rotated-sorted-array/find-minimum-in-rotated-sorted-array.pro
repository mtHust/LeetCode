TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    find-minimum-in-rotated-sorted-array.h

