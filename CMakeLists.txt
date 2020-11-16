cmake_minimum_required(VERSION 3.15)

project(Physika_Cloud)

set(CLOUD_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(CLOUD_BINARY_DIR ${PROJECT_BINARY_DIR})

# execute_process(
#     COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Cplusplus/SatImage/Utility/build
#     COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR}/Cplusplus/SatImage/Utility -B ${CMAKE_BINARY_DIR}/Cplusplus/SatImage/Utility/build
# )

# import OpenCV part
include(ExternalProject)
set(CLOUD_OpenCV_SOURCE_DIR ${CLOUD_SOURCE_DIR}/Extern/opencv-2.4.13)
set(CLOUD_OpenCV_BINARY_DIR ${CLOUD_BINARY_DIR}/Extern/opencv-2.4.13)

ExternalProject_Add(
    CLOUD_OPENCV
    PREFIX ${CLOUD_OpenCV_BINARY_DIR}
    SOURCE_DIR ${CLOUD_OpenCV_SOURCE_DIR}
    BINARY_DIR ${CLOUD_OpenCV_BINARY_DIR}/build
    STAMP_DIR ${PREFIX}/stamp
    
    CMAKE_ARGS -DWITH_CUDA=OFF -DBUILD_TESTS=OFF -DBUILD_DOCS=OFF -DWITH_EIGEN=OFF -DWITH_OPENCL=OFF -DBUILD_SHARED_LIBS=OFF
            -DBUILD_opencv_apps=OFF -DBUILD_ZLIB=OFF -DBUILD_opencv_apps=OFF -DBUILD_opencv_calib3d=OFF -DBUILD_opencv_features2d=OFF
            -DBUILD_opencv_flann=OFF -DBUILD_opencv_objdetect=OFF -DBUILD_opencv_video=OFF -DBUILD_opencv_superes=OFF
            # -D OpenCV_DIR=${CLOUD_OpenCV_BINARY_DIR}/build
 )
# set(CLOUD_OpenCV_INCLUDE_DIR ${CLOUD_OpenCV_BINARY_DIR}/build/install/include)
# set(OPENCV_CONFIG_DIR ${CLOUD_OPENCV_BINARY_DIR}/build/install/staticlib)
# set(OPENCV_CONFIG_DIR ${CLOUD_OPENCV_SOURCE_DIR})
set(CLOUD_OpenCV_INCLUDE_DIR ${CLOUD_OpenCV_SOURCE_DIR}/install-include)
set(CLOUD_OpenCV_LIB_DIR ${CLOUD_OpenCV_BINARY_DIR}/build/install/staticlib)



# import CGAL part



# import OpenMesh part



# physika_cloud part
set(CLOUD_PYTHON_SOURCE_PATH ${PROJECT_SOURCE_DIR}/Python)
set(PYBIND11_DIR ${PROJECT_SOURCE_DIR}/Extern/pybind11)

set(CLOUD_Eigen_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Extern/Eigen-3.3.7)

include_directories(
    ${CLOUD_Eigen_INCLUDE_DIR}
    ${CLOUD_OpenCV_INCLUDE_DIR}
)

add_subdirectory(./Extern)
add_subdirectory(./Cplusplus)
add_subdirectory(./Examples)