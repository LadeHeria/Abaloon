PROJECT(New)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
FILE(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
FIND_PACKAGE(Imagine)

ImagineAddExecutable(New annexe.h annexe.cpp affiche.h affiche.cpp Main.cpp plateau.h plateau.cpp)
ImagineUseModules(New Graphics)
