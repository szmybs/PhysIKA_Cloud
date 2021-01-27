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

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE tcdsmUtil
    PRIVATE tcdsmModel
    netCDFCxx-4.2
    ${OPENSCENEGRAPH_LIBRARIES}
)

install(
        TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin
        RUNTIME DESTINATION bin
)