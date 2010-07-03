cmake_minimum_required(VERSION 2.8)

project(Jaytrace)

set(CMAKE_MODULE_PATH ${Jaytrace_SOURCE_DIR}/cmake/)

find_package(Qt4 REQUIRED)
find_package(Eigen2 REQUIRED)

#source files used both by the main program and the test program
set(common_sources
	CompositeNode.cpp
	IntersectionLibrary.cpp
	Node.cpp
	Ray.cpp
	RayObject.cpp
	ScalingNode.cpp
	Sphere.cpp
	TransformNode.cpp
	TranslationNode.cpp)

#source files specific to the test program
set(jaytraceTest_sources
	main.cpp
	tests/IntersectionLibraryTest.cpp
	tests/RayTest.cpp
	tests/SceneGraphTest.cpp
	tests/SphereTest.cpp
	tests/TransformNodeTest.cpp)

#header files of classes with the Q_OBJECT macro
#these classes must be processed by the moc
set(jaytraceTest_qobject_headers
	tests/IntersectionLibraryTest.h
	tests/RayTest.h
	tests/SceneGraphTest.h
	tests/SphereTest.h
	tests/TransformNodeTest.h)

qt4_wrap_cpp(jaytraceTest_moc_sources ${jaytraceTest_qobject_headers})

set(jaytraceTest_all_sources ${jaytraceTest_sources} ${jaytraceTest_moc_sources} ${common_sources})

set(QT_USE_QTTEST true)

include(${QT_USE_FILE})
include_directories(
	${EIGEN2_INCLUDE_DIR}
	${Jaytrace_SOURCE_DIR}
)

add_definitions(${QT_DEFINITIONS})

add_executable(jaytraceTest ${jaytraceTest_all_sources})

target_link_libraries(jaytraceTest ${QT_LIBRARIES})
