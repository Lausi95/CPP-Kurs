cmake_minimum_required(VERSION 3.6)
project(Playground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include)

set(SOURCE_FILES main.cpp include/Camera.h src/Camera.cpp include/World.h src/World.cpp include/Input.h src/Input.cpp include/Texture.h src/Texture.cpp include/Rectangle.h src/Rectangle.cpp include/Tile.h src/Tile.cpp include/Entity.h src/Entity.cpp include/entities/SimpleEntity.h include/entities/Button.h include/entities/Player.h src/entities/Player.cpp include/state/Worlds.h src/SoundSystem.cpp include/SoundSystem.h src/MenuFactory.cpp include/MenuFactory.h include/GlobalSettings.h)
add_executable(Playground ${SOURCE_FILES})

target_link_libraries(Playground SDL2 SDL2_image SDL2_ttf SDL2_mixer)