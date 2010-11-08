cmake_minimum_required(VERSION 2.8)

project(Jaytrace)

set(CMAKE_MODULE_PATH ${Jaytrace_SOURCE_DIR}/cmake/)

find_package(Qt4 REQUIRED)
find_package(Eigen2 REQUIRED)

#source files used both by the main program and the test program
set(core_sources
	Color.cpp
	CompositeNode.cpp
	IntersectionLibrary.cpp
	Light.cpp
	Material.cpp
	MaterialNode.cpp
	Node.cpp
	Ray.cpp
	RayObject.cpp
	RaytraceRenderer.cpp
	Renderer.cpp
	ScalingNode.cpp
	Sphere.cpp
	TransformNode.cpp
	TranslationNode.cpp)

#source files specific to the test program
set(jaytraceTest_sources
	tests/main.cpp
	tests/IntersectionLibraryTest.cpp
	tests/MaterialTest.cpp
	tests/RayTest.cpp
	tests/SceneGraphTest.cpp
	tests/SphereTest.cpp
	tests/TransformNodeTest.cpp)

#header files of classes with the Q_OBJECT macro
#these classes must be processed by the moc
set(jaytraceTest_qobject_headers
	tests/IntersectionLibraryTest.h
	tests/MaterialTest.h
	tests/RayTest.h
	tests/SceneGraphTest.h
	tests/SphereTest.h
	tests/TransformNodeTest.h)

qt4_wrap_cpp(jaytraceTest_moc_sources ${jaytraceTest_qobject_headers})

set(jaytraceTest_all_sources ${jaytraceTest_sources} ${jaytraceTest_moc_sources})

set(QT_USE_QTTEST true)

include(${QT_USE_FILE})
include_directories(
	${EIGEN2_INCLUDE_DIR}
	${Jaytrace_SOURCE_DIR}
)

add_definitions(-Wall -O2 -ggdb ${QT_DEFINITIONS})

add_library(JaytraceCore ${core_sources})

add_executable(jaytrace main.cpp)
add_executable(jaytraceTest ${jaytraceTest_all_sources})

target_link_libraries(jaytrace JaytraceCore ${QT_LIBRARIES})
target_link_libraries(jaytraceTest JaytraceCore ${QT_LIBRARIES})
