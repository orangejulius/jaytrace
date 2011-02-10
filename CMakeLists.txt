cmake_minimum_required(VERSION 2.8)

project(Jaytrace)

set(CMAKE_MODULE_PATH ${Jaytrace_SOURCE_DIR}/cmake/)

option(enableGui "Build the qt4 jaytrace executable" ON)
option(enableTests "Build the test executable" ON)

set(CMAKE_CXX_FLAGS "-Wall")

find_package(Eigen2 REQUIRED)
find_package(Qt4 REQUIRED)

#source files used both by the main program and the test program
set(core_sources
	Camera.cpp
	Color.cpp
	IntersectionLibrary.cpp
	Light.cpp
	Material.cpp
	MaterialNode.cpp
	Node.cpp
	Poisson.cpp
	Ray.cpp
	Raytracer.cpp
	RotationNode.cpp
	ScalingNode.cpp
	Scene.cpp
	SceneObject.cpp
	Sphere.cpp
	TransformNode.cpp
	TranslationNode.cpp)

if (enableGui)
	#source files specific to the qt4 gui interface
	set(jaytraceQt_sources
		gui/main.cpp
		gui/MainWindow.cpp
		gui/OpenGLWidget.cpp
		gui/RaytracerWidget.cpp)

	#header files of classes with the Q_OBJECT macro
	#these classes must be processed by the moc
	set(jaytraceQt_qobject_headers
		gui/MainWindow.h
		gui/OpenGLWidget.h
		gui/RaytracerWidget.h)

	qt4_wrap_cpp(jaytraceQt_moc_sources ${jaytraceQt_qobject_headers})

	set(jaytraceQt_all_sources ${jaytraceQt_sources} ${jaytraceQt_moc_sources})

	set(QT_USE_QTOPENGL true)

	find_package(OpenGL REQUIRED)
endif (enableGui)

if (enableTests)
	#source files specific to the test program
	set(jaytraceTest_sources
		tests/main.cpp
		tests/CameraTest.cpp
		tests/IntersectionLibraryTest.cpp
		tests/MaterialTest.cpp
		tests/RayTest.cpp
		tests/SceneGraphTest.cpp
		tests/SphereTest.cpp
		tests/TransformNodeTest.cpp)

	#header files of classes with the Q_OBJECT macro
	#these classes must be processed by the moc
	set(jaytraceTest_qobject_headers
		tests/CameraTest.h
		tests/IntersectionLibraryTest.h
		tests/MaterialTest.h
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

if (enableGui)
	add_executable(jaytraceQt ${jaytraceQt_all_sources})
	target_link_libraries(jaytraceQt JaytraceCore ${QT_LIBRARIES}
		${OPENGL_glu_LIBRARY})
endif (enableGui)

if (enableTests)
	add_executable(jaytraceTest ${jaytraceTest_all_sources})
	target_link_libraries(jaytraceTest JaytraceCore ${QT_LIBRARIES})
endif (enableTests)
