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
        Entity.cpp
        Input.cpp
        logging.cpp
        Texture.cpp
        Tile.cpp
        Timer.cpp
        Window.cpp
        main.cpp include/LevelMap.h LevelMap.cpp)
include_directories(Punktefresser include)
add_executable(Punktefresser ${SOURCE_FILES})

target_link_libraries(Punktefresser SDL2 SDL2_image SDL2_ttf)