project(tcdsmModel)

SET(TARGET_H
        export.h
        config.h
        model.h
        particles.h
        netcdfparser.h
        netcdfset.h
        netcdfclassifier.h
        wrfnetcdfparser.h
        netcdfparserbuilder.h
)
SET(TARGET_SRC
        model.cpp
        particles.cpp
        netcdfclassifier.cpp
        netcdfset.cpp
        wrfnetcdfparser.cpp
        netcdfparserbuilder.cpp
)

add_library(${PROJECT_NAME} SHARED ${TARGET_H} ${TARGET_SRC})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE tcdsmUtil
    netCDFCxx-4.2
    ${OPENSCENEGRAPH_LIBRARIES}
)

install(
        TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin
        RUNTIME DESTINATION bin
)


