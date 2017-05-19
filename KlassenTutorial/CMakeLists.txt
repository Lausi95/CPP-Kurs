cmake_minimum_required(VERSION 3.6)
project(KlassenTutorial)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Person.cpp Person.h)
add_executable(KlassenTutorial ${SOURCE_FILES})