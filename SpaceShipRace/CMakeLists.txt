cmake_minimum_required(VERSION 3.7)
project(SpaceShipRace)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(SpaceShipRace ${SOURCE_FILES})

target_link_libraries(SpaceShipRace SDL2 SDL2_image SDL2_ttf)