cmake_minimum_required(VERSION 2.8)

project(Jaytrace)

set(CMAKE_MODULE_PATH ${Jaytrace_SOURCE_DIR}/cmake/)
add_definitions(-DQT_NO_DEBUG_OUTPUT)

option(enableTests "Build the test executable" ON)

set(CMAKE_CXX_FLAGS "-Wall -fopenmp")

find_package(Eigen2 REQUIRED)
find_package(Qt4 REQUIRED)

#source files used both by the main program and the test program
set(core_sources
	Camera.cpp
	Color.cpp
	Cube.cpp
	CubeScene.cpp
	FourSphereScene.cpp
	IntersectionLibrary.cpp
	Light.cpp
	Material.cpp
	MaterialNode.cpp
	Node.cpp
	Plane.cpp
	Poisson.cpp
	Ray.cpp
	RayObject.cpp
	Raytracer.cpp
	RaytraceRenderer.cpp
	Renderer.cpp
	RotationNode.cpp
	ScalingNode.cpp
	Scene.cpp
	Sphere.cpp
	SpiralScene.cpp
	TransformNode.cpp
	TranslationNode.cpp)

if (enableTests)
	#source files specific to the test program
	set(jaytraceTest_sources
		tests/main.cpp
		tests/AngleTest.cpp
		tests/CameraTest.cpp
		tests/CubeTest.cpp
		tests/IntersectionLibraryTest.cpp
		tests/MaterialTest.cpp
		tests/PlaneTest.cpp
		tests/RayTest.cpp
		tests/SceneGraphTest.cpp
		tests/SphereTest.cpp
		tests/TransformNodeTest.cpp)

	#header files of classes with the Q_OBJECT macro
	#these classes must be processed by the moc
	set(jaytraceTest_qobject_headers
		tests/AngleTest.h
		tests/CameraTest.h
		tests/CubeTest.h
		tests/IntersectionLibraryTest.h
		tests/MaterialTest.h
		tests/PlaneTest.h
		tests/RayTest.h
		tests/SceneGraphTest.h
		tests/SphereTest.h
		tests/TransformNodeTest.h)

	qt4_wrap_cpp(jaytraceTest_moc_sources ${jaytraceTest_qobject_headers})

	set(jaytraceTest_all_sources ${jaytraceTest_sources} ${jaytraceTest_moc_sources})

	set(QT_USE_QTTEST true)
endif (enableTests)

include(${QT_USE_FILE})

include_directories(
	${EIGEN2_INCLUDE_DIR}
	${Jaytrace_SOURCE_DIR}
)

add_definitions(-O2 -ggdb ${QT_DEFINITIONS})

add_library(JaytraceCore ${core_sources})

add_executable(jaytrace main.cpp)
target_link_libraries(jaytrace JaytraceCore ${QT_LIBRARIES})

if (enableTests)
	add_executable(jaytraceTest ${jaytraceTest_all_sources})
	target_link_libraries(jaytraceTest JaytraceCore ${QT_LIBRARIES})
endif (enableTests)
