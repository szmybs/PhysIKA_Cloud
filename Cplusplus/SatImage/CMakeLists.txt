project(SatImageALL)

set(SatImage_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(SatImage_BINARY_DIR ${PROJECT_BINARY_DIR})

option(CLOUD_SAT_TYPHOON "option for satimage typhoon" ON)

if(CLOUD_SAT_TYPHOON)
    add_subdirectory(Utility)
    add_subdirectory(Typhoon)
endif()