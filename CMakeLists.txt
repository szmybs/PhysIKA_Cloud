cmake_minimum_required(VERSION 3.15)

project(Physika_Cloud)

set(CLOUD_RUNTIME_INSTALL_DIR ${PROJECT_BINARY_DIR}/bin)
set(CLOUD_PYTHON_SOURCE_PATH ./Python)
set(PYBIND11_DIR ./Extern/pybind11)
# message("${CLOUD_RUNTIME_INSTALL_DIR}")

include_directories(
    ./Extern
)

add_subdirectory(./Extern)
add_subdirectory(./Cplusplus)

execute_process(
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Cplusplus/SatImage/Utility/build
    COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR}/Cplusplus/SatImage/Utility -B ${CMAKE_BINARY_DIR}/Cplusplus/SatImage/Utility/build
)