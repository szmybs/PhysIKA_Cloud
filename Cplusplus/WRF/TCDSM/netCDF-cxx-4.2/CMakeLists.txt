project(netCDFCxx-4.2)
set(CMAKE_CXX_STANDARD 11)

set(SRC_LIST
    ${PROJECT_SOURCE_DIR}/netcdf.cpp
    ${PROJECT_SOURCE_DIR}/netcdfcpp.h
    ${PROJECT_SOURCE_DIR}/ncvalues.cpp
    ${PROJECT_SOURCE_DIR}/ncvalues.h
)

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

target_link_libraries(
    ${PROJECT_NAME}
    ${netCDF_LIBRARIES}
)
