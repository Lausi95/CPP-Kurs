#ifndef SDL_GAME_STDAFX_H
#define SDL_GAME_STDAFX_H

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "Direction.h"

#include "logging.h"

#include "Texture.h"
#include "LevelMap.h"

#include "Entity.h"
#include "entities/MovableEntity.h"
#include "entities/Pacman.h"
#include "entities/Enemy.h"
#include "entities/StaticEntity.h"

#include "Input.h"
#include "Tile.h"
#include "Timer.h"
#include "Window.h"

#endif //SDL_GAME_STDAFX_H
