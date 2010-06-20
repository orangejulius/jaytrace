# ------------------------------------------------
# Project created by QtCreator 2010-01-31T16:45:48
# ------------------------------------------------

QT -= gui

TARGET = Jaytrace

CONFIG += debug
CONFIG += console
CONFIG -= app_bundle
CONFIG += qtestlib

TEMPLATE = app

INCLUDEPATH += /usr/include/eigen2

SOURCES += main.cpp \
	CompositeNode.cpp \
	Node.cpp \
	Ray.cpp \
	tests/RayTest.cpp \
	tests/SceneGraphTest.cpp
HEADERS += CompositeNode.h \
	Node.h \
	Ray.h \
	tests/RayTest.h \
	tests/SceneGraphTest.h
