# CMakeList.txt : CMake project for DesignPattern, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project("Factory")

add_executable(${PROJECT_NAME} main.cpp creature.h spawner.h)
