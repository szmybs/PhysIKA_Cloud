project(ImageCumulus)
set(CMAKE_CXX_STANDARD 11)

find_package(pybind11 REQUIRED CONFIG PATHS ${PYBIND11_DIR})

aux_source_directory(. SRC_LIST)
pybind11_add_module(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(
    ${PROJECT_NAME}
    CLOUD_OpenMesh
)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION lib
)

