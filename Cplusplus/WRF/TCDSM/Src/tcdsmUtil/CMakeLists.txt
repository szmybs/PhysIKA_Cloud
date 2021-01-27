project(tcdsmUtil)

SET(TARGET_H
        export.h
        config.h
        util.h
        ScopedLog.h
)

SET(TARGET_SRC
        util.cpp
        ScopedLog.cpp
)

add_library(${PROJECT_NAME} SHARED ${TARGET_H} ${TARGET_SRC})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE ${OPENSCENEGRAPH_LIBRARIES}
)

install(
        TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin
        RUNTIME DESTINATION bin
)