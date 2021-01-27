project(Cloud_Gen_Based_Euler)
set(CMAKE_CXX_STANDARD 11)

find_package(pybind11 REQUIRED CONFIG PATHS ${PYBIND11_DIR})

aux_source_directory(. SRC_LIST)
pybind11_add_module(Cloud_Gen_Based_Euler ${SRC_LIST})

install(
    TARGETS Cloud_Gen_Based_Euler
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION lib
}