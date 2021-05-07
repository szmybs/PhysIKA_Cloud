PROJECT(FluidEvolution LANGUAGES CXX CUDA)

set(SIMULATION_LINK_LIBRARIES AntTweakBar glew PositionBasedDynamics Simulation Utils)
set(SIMULATION_DEPENDENCIES AntTweakBar glew PositionBasedDynamics Simulation Utils)

if(WIN32)
  set(SIMULATION_LINK_LIBRARIES freeglut opengl32.lib glu32.lib ${SIMULATION_LINK_LIBRARIES})
  set(SIMULATION_DEPENDENCIES freeglut ${SIMULATION_DEPENDENCIES})
else()
  find_package(GLUT REQUIRED)
  find_package(OpenGL REQUIRED)

  set(SIMULATION_LINK_LIBRARIES
    ${SIMULATION_LINK_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${OPENGL_LIBRARIES}
  )
endif()

############################################################
# Discregrid------zzl
############################################################
#include_directories(${ExternalInstallDir}/Discregrid/include)
#set(FluidDemo_DEPENDENCIES ${FluidDemo_DEPENDENCIES} ExternalProject_Discregrid)
#add_dependencies(FluidDemo ${FluidDemo_DEPENDENCIES})

include_directories(
	.
	${EigenDir} 
  ${GlewDir}
  ${GlutDir}
	${PROJECT_PATH}/Extern/Discregrid/discregrid/include
	)

set(SIMULATION_DEPENDENCIES ${SIMULATION_DEPENDENCIES} ExternalProject_Discregrid)
set(SIMULATION_LINK_LIBRARIES ${SIMULATION_LINK_LIBRARIES} 
	optimized Discregrid 
	debug Discregrid_d)
link_directories(${PROJECT_BINARY_PATH}/Extern/Discregrid/build/install/lib)
############################################################
# Discregrid------zzl
############################################################

file(                                                                           #利用glob命令读取所有源文件list
    GLOB_RECURSE SRC_LIST 
    LIST_DIRECTORIES false
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.h*"
)

file(                                                                           #利用glob命令读取所有源文件list
    GLOB_RECURSE SRC_CUDA_LIST 
    LIST_DIRECTORIES false
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.cu*"
)

if(CLOUD_PYTHON)
    list(REMOVE_ITEM SRC_LIST ${PROJECT_SOURCE_DIR}/Gen2py.cpp)

    add_library(${PROJECT_NAME}
      ${SRC_LIST}
      ${SRC_CUDA_LIST}
      ${VIS_FILES}          
      ${PROJECT_PATH}/Common/Common.h
    )

    pybind11_add_module(py${PROJECT_NAME}           
      ${PROJECT_SOURCE_DIR}/Gen2py.cpp
    )

    set_target_properties(py${PROJECT_NAME} PROPERTIES FOLDER "${FOLDER_PREFIX}FluidEvolution")
    set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "${FOLDER_PREFIX}FluidEvolution")

    set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
    set_target_properties(${PROJECT_NAME} PROPERTIES CUDA_RESOLVE_DEVICE_SYMBOLS ON)

    add_dependencies(${PROJECT_NAME} ${SIMULATION_DEPENDENCIES})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SIMULATION_LINK_LIBRARIES})
    target_link_libraries(py${PROJECT_NAME} PRIVATE ${PROJECT_NAME})
else()
    list(REMOVE_ITEM SRC_LIST ${PROJECT_SOURCE_DIR}/Gen2py.cpp)
    add_library(${PROJECT_NAME}
        ${SRC_LIST}
        ${SRC_CUDA_LIST}
        ${VIS_FILES}          
        ${PROJECT_PATH}/Common/Common.h
    )
    add_dependencies(${PROJECT_NAME} ${SIMULATION_DEPENDENCIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SIMULATION_LINK_LIBRARIES})
    
    set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "${FOLDER_PREFIX}FluidEvolution")
    set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
    set_target_properties(${PROJECT_NAME} PROPERTIES CUDA_RESOLVE_DEVICE_SYMBOLS ON)
endif()

add_definitions(-DTW_NO_LIB_PRAGMA -DTW_STATIC -DFREEGLUT_LIB_PRAGMAS=0)



if(CLOUD_PYTHON)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                    $<$<CONFIG:Debug>:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/freeglutd.dll> 
                    $<$<CONFIG:Release>:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/freeglut.dll>
                    ${CLOUD_BINARY_DIR}/Python/FluidEvolution
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<$<CONFIG:Debug>:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/glewd.dll> 
                    $<$<CONFIG:Release>:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/glew.dll>
                    ${CLOUD_BINARY_DIR}/Python/FluidEvolution
    )
endif()

if(CLOUD_PYTHON)
    install(
        TARGETS py${PROJECT_NAME}
        LIBRARY DESTINATION ${CLOUD_BINARY_DIR}/Python/FluidEvolution
    )
else()
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
endif()




