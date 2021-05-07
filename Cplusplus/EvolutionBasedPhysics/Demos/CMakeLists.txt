include(Visualization/CMakeLists.txt)

include_directories(
	.
	./FluidDemo
	./Utils
	./P2V
	./Simulation
)


add_subdirectory(Simulation)
add_subdirectory(Utils)
add_subdirectory(FluidDemo)