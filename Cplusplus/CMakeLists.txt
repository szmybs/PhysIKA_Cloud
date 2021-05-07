include_directories(
    ./
    ${PhysIKA_Source_DIR}
)

add_subdirectory(./WRF)

add_subdirectory(./SatImage)

add_subdirectory(./Image)

option(CLOUD_EVOLUTION_BASED_PHYSICS "option for evolution based physics" ON)
if(CLOUD_EVOLUTION_BASED_PHYSICS)
    add_subdirectory(./EvolutionBasedPhysics)
endif()

