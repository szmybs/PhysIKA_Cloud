PROJECT(SatImageTyphoon)

cmake_minimum_required(VERSION 3.12)

aux_source_directory(. SRC_LIST)
add_library(${PROJECT_NAME} ${SRC_LIST})

set(OpenCV_DIR E:/opencv-4.1.1/build)
find_package(OpenCV REQUIRED)
include_directories(
        ..
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} Utility)