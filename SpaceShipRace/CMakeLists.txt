cmake_minimum_required(VERSION 3.7)
project(SpaceShipRace)

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
        main.cpp)
add_executable(SpaceShipRace ${SOURCE_FILES})

target_link_libraries(SpaceShipRace SDL2 SDL2_image SDL2_ttf)