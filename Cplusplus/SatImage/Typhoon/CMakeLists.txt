PROJECT(SatImageTyphoon)

cmake_minimum_required(VERSION 3.12)


aux_source_directory(. SRC_LIST)
add_library(${PROJECT_NAME} ${SRC_LIST})

include_directories(
    ${SatImage_SOURCE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME} 
    SatImageUtility
    CLOUD_OpenCV
)

install(
    TARGETS ${PROJECT_NAME}
    # CONFIGURATIONS Debug
    ARCHIVE DESTINATION ${CLOUD_INSTALL_ARCHIVE_DIR}
)