cmake_minimum_required(VERSION 3.6)
project(SDL_Game)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

AUX_SOURCE_DIRECTORY(. sources)

add_executable(SDL_Game ${sources})

target_link_libraries(SDL_Game SDL2 SDL2_image)
