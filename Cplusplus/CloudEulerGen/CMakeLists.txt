project(Cloud_Gen_Based_Euler)
set(CMAKE_CXX_STANDARD 11)

find_package(pybind11 REQUIRED CONFIG PATHS ${PYBIND11_DIR})

aux_source_directory(. Cloud_Gen_Based_Euler)
pybind11_add_module(Cloud_Gen_Based_Euler ${Cloud_Gen_Based_Euler})

install(TARGETS Cloud_Gen_Based_Euler
    RUNTIME DESTINATION ${CLOUD_PYTHON_SOURCE_PATH}/${PROJECT_NAME}
    LIBRARY DESTINATION ${CLOUD_PYTHON_SOURCE_PATH}/${PROJECT_NAME}
    ARCHIVE DESTINATION ${CLOUD_PYTHON_SOURCE_PATH}/${PROJECT_NAME}
}