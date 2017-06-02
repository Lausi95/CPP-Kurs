cmake_minimum_required(VERSION 3.6)
project(SDL_Game)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(SDL_Game
        Entity.cpp
        Input.cpp
        logging.cpp
        main.cpp
        Texture.cpp
        Tile.cpp
        Timer.cpp
        Window.cpp
        Room.cpp
        include/Entity.h
        include/Input.h
        include/logging.h
        include/Tile.h
        include/Texture.h
        include/Timer.h
        include/Window.h
        include/stdafx.h
        include/Room.h)

target_link_libraries(SDL_Game SDL2 SDL2_image SDL2_ttf)
