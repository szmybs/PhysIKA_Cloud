QT       -= core gui

TARGET = tcdsmModeler
TEMPLATE = lib

DEFINES += TCDSM_MODELER_LIBRARY

#第三方依赖
#THIRD += OSG
#本地库依赖
DEPENDS += Util Model
#导入配置文集
include(../build.pri)

SOURCES += modeler.cpp \
    simplemodeler.cpp \
    tcdsmmodeler.cpp


HEADERS += $${HEADPATH}/modeler.h \
    $${HEADPATH}/export.h \
    $${HEADPATH}/config.h \
    $${HEADPATH}/simplemodeler.h \
    $${HEADPATH}/tcdsmmodeler.h

