project(tcdsmModeler)

SET(TARGET_H
        export.h
        config.h
        modeler.h
        simplemodeler.h
)

SET(TARGET_SRC
        modeler.cpp
        simplemodeler.cpp
)

add_library(${PROJECT_NAME} SHARED ${TARGET_H} ${TARGET_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "WRF/TCDSM")

target_link_libraries(
    ${PROJECT_NAME}
    tcdsmModel
    # PRIVATE tcdsmUtil
    # PRIVATE tcdsmModel
    # netCDFCxx-4.2
    # ${CLOUD_OSG_LIBS}
)

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Debug
    ARCHIVE DESTINATION lib/Debug
    LIBRARY DESTINATION bin/Debug
    RUNTIME DESTINATION bin/Debug
)
install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Release
    ARCHIVE DESTINATION lib/Release
    LIBRARY DESTINATION bin/Release
    RUNTIME DESTINATION bin/Release
)