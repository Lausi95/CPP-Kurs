cmake_minimum_required(VERSION 3.7)
project(BurningKiddies)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp include/BurnEngine.h src/BurnEngine.cpp include/Level.h src/Level.cpp)

include_directories(BurningKiddies include)
add_executable(BurningKiddies ${SOURCE_FILES})

target_link_libraries(BurningKiddies SDL2 SDL2_image SDL2_ttf)