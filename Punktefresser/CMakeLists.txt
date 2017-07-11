cmake_minimum_required(VERSION 3.7)
project(Punktefresser)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        include/Entity.h
        include/Input.h
        include/logging.h
        include/stdafx.h
        include/Texture.h
        include/Tile.h
        include/Timer.h
        include/Window.h
        include/LevelMap.h
        include/Direction.h
        src/Entity.cpp
        src/Input.cpp
        src/logging.cpp
        src/Texture.cpp
        src/Tile.cpp
        src/Timer.cpp
        src/Window.cpp
        src/main.cpp
        src/LevelMap.cpp
        src/Direction.cpp)

include_directories(Punktefresser include)
add_executable(Punktefresser ${SOURCE_FILES})

target_link_libraries(Punktefresser SDL2 SDL2_image SDL2_ttf)