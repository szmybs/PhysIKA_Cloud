cmake_minimum_required(VERSION 3.10)

project(EvolutionBasedPhysics)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)                                                         
set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
                            
set(PROJECT_PATH ${PROJECT_SOURCE_DIR})
set(PROJECT_BINARY_PATH ${PROJECT_BINARY_DIR})

include_directories(${PROJECT_PATH})

set(EigenDir ${CLOUD_Eigen_INCLUDE_DIR})
set(GlewDir "${PROJECT_PATH}/Extern/glew/include")
set(GlutDir "${PROJECT_PATH}/Extern/freeglut/include")
  
add_definitions(-D_CRT_SECURE_NO_DEPRECATE)

if (WIN32)
    subdirs(
      ${PROJECT_PATH}/Extern/freeglut 
      ${PROJECT_PATH}/Extern/AntTweakBar 
      ${PROJECT_PATH}/Extern/glew 
      ${PROJECT_PATH}/Extern/md5 
      ./Demos 
      ./PositionBasedDynamics
    )
else()
  # subdirs(extern/AntTweakBar extern/glew extern/md5 Demos PositionBasedDynamics)
endif()

include(ExternalProject)

## Discregrid
ExternalProject_Add(
   ExternalProject_Discregrid
   PREFIX ${PROJECT_BINARY_DIR}/Extern/Discregrid/build
   SOURCE_DIR  ${PROJECT_PATH}/Extern/Discregrid
   BINARY_DIR  ${PROJECT_BINARY_DIR}/Extern/Discregrid/build
   CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/Extern/Discregrid/build/install 
              -DBUILD_CMD_EXECUTABLE:BOOL=0 -DEIGEN3_INCLUDE_DIR:PATH=${EigenDir}
)
set_target_properties(ExternalProject_Discregrid PROPERTIES FOLDER "${FOLDER_PREFIX}ExternalProjectTargets")

