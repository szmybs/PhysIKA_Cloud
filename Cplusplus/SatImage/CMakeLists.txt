project(SatImageALL)

set(SatImage_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(SatImage_BINARY_DIR ${PROJECT_BINARY_DIR})

set(SatImage_INSTALL_LIB_DIR ${CLOUD_BINARY_DIR}/lib)
set(SatImage_INSTALL_RUNTIME_DIR ${CLOUD_BINARY_DIR}/bin)

add_subdirectory(Utility)
# add_subdirectory(Cumulus)
add_subdirectory(Typhoon)