option(CLOUD_WRF "option for wrf" OFF)
if(CLOUD_WRF)
    add_subdirectory(./TCDSM)
endif()



if(CLOUD_WRF AND NOT USE_PREBUILT_OSG)
    if(WIN32)

        set(CLOUD_OSG_SOURCE_DIR ${CLOUD_SOURCE_DIR}/Extern/opencv-2.4.13)
        set(CLOUD_OSG_BINARY_DIR ${CLOUD_BINARY_DIR}/Extern/opencv-2.4.13/build)
        
        set(CLOUD_OSG_INCLUDE_DIR ${CLOUD_OSG_SOURCE_DIR}/install-include)
        set(CLOUD_OSG_LIB_DIR ${CLOUD_OSG_BINARY_DIR}/install/lib)
        set(CLOUD_OSG_BIN_DIR ${CLOUD_OSG_BINARY_DIR}/install/bin)


        add_library(CLOUD_OSG ${CLOUD_SOURCE_DIR}/Extern/openscenegraph_interface.cpp)
        set_target_properties(CLOUD_OSG PROPERTIES FOLDER "ExternalProjectTargets")

    
        add_custom_command(
            TARGET CLOUD_OSG
            PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -S ${CLOUD_OSG_SOURCE_DIR} -B ${CLOUD_OSG_BINARY_DIR} -A x64
            COMMAND ${CMAKE_COMMAND} --build ${CLOUD_OSG_BINARY_DIR} --config $<$<CONFIG:>:Undefined>$<$<NOT:$<CONFIG:>>:$<CONFIG>>
        )

        
        set(cloud_opencv_libs
            opencv_core
            opencv_highgui
            opencv_imgproc
        )
        set(cloud_opencv_link_list "")
        set(cloud_opencv_shared_files_list "")

        foreach(lib ${cloud_opencv_libs})
            add_library(${lib} SHARED IMPORTED)
            set_target_properties(${lib} PROPERTIES 
                IMPORTED_IMPLIB_DEBUG "${CLOUD_OpenCV_LIB_DIR}/${lib}2413d.lib"
                IMPORTED_LOCATION_DEBUG "${CLOUD_OpenCV_BIN_DIR}/${lib}2413d.dll"
            )
            set_target_properties(${lib} PROPERTIES 
                IMPORTED_IMPLIB_RELEASE "${CLOUD_OpenCV_LIB_DIR}/${lib}2413.lib"
                IMPORTED_LOCATION_RELEASE "${CLOUD_OpenCV_BIN_DIR}/${lib}2413.dll"
            )
            list(APPEND cloud_opencv_link_list ${lib})
            list(
                APPEND cloud_opencv_shared_files_list 
                $<$<CONFIG:Debug>:${CLOUD_OpenCV_BIN_DIR}/${lib}2413d.dll> 
                $<$<CONFIG:Release>:${CLOUD_OpenCV_BIN_DIR}/${lib}2413.dll>
            )
        endforeach()

        target_link_libraries(CLOUD_OpenCV
            ${cloud_opencv_link_list}
        )

    endif()
endif()