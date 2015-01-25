TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    excel-sheet-column-title.h

