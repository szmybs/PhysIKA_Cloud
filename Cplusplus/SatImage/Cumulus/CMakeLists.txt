PROJECT(SatImageCumulus)

cmake_minimum_required(VERSION 3.12)

aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})
add_library(${PROJECT_NAME} ${SRC_LIST})

find_package(CGAL REQUIRED)

set(OpenCV_DIR E:/opencv-4.1.1/build)
find_package(OpenCV REQUIRED)

include_directories(
	..
	${OpenCV_INCLUDE_DIRS}
	${CGAL_INCLUDE_DIRS}
	)

target_link_libraries(${PROJECT_NAME} ${CGAL_LIBRARIES_DIR} ${OpenCV_LIBS} Utility)
#target_link_libraries(${PROJECT_NAME}_lib ${CGAL_LIBS} ${OpenCV_LIBS})

