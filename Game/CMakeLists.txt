cmake_minimum_required(VERSION 3.6)
project(HalloWelt)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

AUX_SOURCE_DIRECTORY(. sources)

add_executable(HalloWelt ${sources})

target_link_libraries(HalloWelt SDL2 SDL2_image)
