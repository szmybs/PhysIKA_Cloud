project(TyphoonExample)

link_libraries(SatImageTyphoon)

add_executable(${PROJECT_NAME} main.cpp)

# install(
#     TARGETS ${PROJECT_NAME}
#     RUNTIME DESTINATION ${SatImage_INSTALL_LIB_DIR}
# )