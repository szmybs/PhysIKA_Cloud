PROJECT(SatImageTyphoon)

cmake_minimum_required(VERSION 3.12)

aux_source_directory(. SRC_LIST)
add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

# message("${OPENCV_CONFIG_DIR}")
# find_package(OpenCV REQUIRED CONFIG PATHS ${OPENCV_CONFIG_DIR})

include_directories(
        ${SatImage_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} ${CLOUD_OpenCV_LIB_DIR}/*.lib SatImageUtility)

install(
    TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${SatImage_INSTALL_LIB_DIR}
)