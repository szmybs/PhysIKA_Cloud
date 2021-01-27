QT       -= core gui

TARGET = tcdsmUtil
TEMPLATE = lib

DEFINES += TCDSM_UTIL_LIBRARY

#第三方依赖
THIRD += OSG
#导入配置文集
include(../build.pri)

SOURCES += \
    util.cpp \
    ScopedLog.cpp \
    osgimageoperator.cpp \
    math.cpp

HEADERS += $${HEADPATH}/export.h \
    $${HEADPATH}/config.h \
    $${HEADPATH}/util.h \
    $${HEADPATH}/ScopedLog.h \
    $${HEADPATH}/osgimageoperator.h \
    $${HEADPATH}/math.h

