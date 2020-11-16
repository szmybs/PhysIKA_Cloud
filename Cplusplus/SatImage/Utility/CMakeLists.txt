project(SatImageUtility)

aux_source_directory(. SRC_LIST)
add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

install(
    TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${SatImage_INSTALL_LIB_DIR}
)
