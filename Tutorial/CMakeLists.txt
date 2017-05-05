cmake_minimum_required(VERSION 3.6)
project(Tutorial)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp DiceGames.cpp DiceGames.h Room.cpp Room.h TextAdventure.cpp TextAdventure.h)
add_executable(Tutorial ${SOURCE_FILES})