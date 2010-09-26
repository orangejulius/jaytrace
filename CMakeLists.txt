project(Jaytrace)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${Jaytrace_SOURCE_DIR}/cmake/)

find_package(Qt4 REQUIRED)
find_package(Eigen2 REQUIRED)

set(jaytrace_sources main.cpp CompositeNode.cpp Node.cpp Ray.cpp ScalingNode.cpp
	Sphere.cpp TransformNode.cpp TranslationNode.cpp tests/RayTest.cpp
	tests/SceneGraphTest.cpp tests/SphereTest.cpp tests/TransformNodeTest.cpp)

set(jaytrace_headers CompositeNode.h Node.h Ray.h ScalingNode.h
	Sphere.h TransformNode.h TranslationNode.h tests/RayTest.h
	tests/SceneGraphTest.h tests/SphereTest.h tests/TransformNodeTest.h)

set(QT_USE_QTTEST true)

qt4_wrap_cpp(jaytrace_headers_moc ${jaytrace_headers})

include(${QT_USE_FILE})
include_directories(
	${EIGEN2_INCLUDE_DIR}
	${Jaytrace_SOURCE_DIR}
)

add_definitions(${QT_DEFINITIONS})

add_executable(jaytrace ${jaytrace_sources} ${jaytrace_headers_moc})
target_link_libraries(jaytrace ${QT_LIBRARIES})
