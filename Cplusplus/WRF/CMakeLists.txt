option(CLOUD_WRF "option for wrf" OFF)
if(CLOUD_WRF)
    add_subdirectory(./TCDSM)
endif()