PROJECT(SatImageTyphoon)
cmake_minimum_required(VERSION 3.12)

aux_source_directory(. SRC_LIST)
add_library(${PROJECT_NAME} ${SRC_LIST})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "SatImage")

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
    CONFIGURATIONS Debug
    ARCHIVE DESTINATION Debug/lib
)

set(HEADER_FILES global.h SatDataCloud_Lite.h)
install(
    FILES ${HEADER_FILES}
    DESTINATION include/Typhoon
)