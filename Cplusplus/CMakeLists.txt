option(CLOUD_EULER "option for euler method" OFF)
if(CLOUD_EULER)
    add_subdirectory(./CloudEulerGen)
endif()

add_subdirectory(./SatImage)