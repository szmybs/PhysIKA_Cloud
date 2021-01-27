project(TCDSM)
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# find_package(netCDF)
# include_directories(${netCDF_INCLUDE_DIR})

# find_package(OpenCV)

# find_package(OpenSceneGraph REQUIRED
#         osgDB
#         osgUtil
#         osgViewer
#         osgGA
#         osgFX
#         osgParticle
#         osgAnimation
#         osgPresentation
#         osgManipulator
#         # osgQt
#         osgShadow
#         osgTerrain
#         osgText
#         osgVolume
#         osgWidget
#         osgSim
#         )
# INCLUDE_DIRECTORIES(${OPENSCENEGRAPH_INCLUDE_DIRS})


include_directories(
        ${PROJECT_SOURCE_DIR}/Src
        ${PROJECT_SOURCE_DIR}/netCDF-cxx-4.2
)

add_subdirectory(${PROJECT_SOURCE_DIR}/netCDF-cxx-4.2)


add_subdirectory(${PROJECT_SOURCE_DIR}/Src)