project(Examples)

include_directories(
    ${CLOUD_SOURCE_DIR}/Cplusplus
    ${CLOUD_SOURCE_DIR}/Cplusplus/SatImage
    ${CLOUD_SOURCE_DIR}/Cplusplus/SatImage/Typhoon
    ${CLOUD_SOURCE_DIR}/Cplusplus/SatImage/Cumulus
    ${CLOUD_SOURCE_DIR}/Cplusplus/CloudEulerGen
)

# add_subdirectory(./TyphoonExample)
add_subdirectory(./CumulusExample)