QT       -= core gui

TARGET = tcdsmModel
TEMPLATE = lib

#预定义宏
DEFINES += TCDSM_MODEL_LIBRARY

#第三方依赖
THIRD += OSG NETCDF TINYXML
#本地库依赖
DEPENDS += Util
#导入配置文集
include(../build.pri)

#头文件
HEADERS += $${HEADPATH}/model.h \
    $${HEADPATH}/export.h \
    $${HEADPATH}/config.h \
    $${HEADPATH}/particles.h \
    $${HEADPATH}/netcdfclassifier.h \
    $${HEADPATH}/netcdfset.h \
    $${HEADPATH}/netcdfparser.h \
    $${HEADPATH}/wrfnetcdfparser.h \
    $${HEADPATH}/netcdfparserbuilder.h \
    $${HEADPATH}/configurenetcdfparser.h


#源文件
SOURCES += model.cpp \
    particles.cpp \
    netcdfclassifier.cpp \
    netcdfset.cpp \
    wrfnetcdfparser.cpp \
    netcdfparserbuilder.cpp \
    configurenetcdfparser.cpp
