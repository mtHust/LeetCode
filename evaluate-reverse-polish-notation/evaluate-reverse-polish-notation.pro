TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    evaluate-reverse-polish-notation.h

