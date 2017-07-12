#include <Entity.h>
#include <stdafx.h>

const int FRAME_SLEEP_TIME = 8;

using texture_ptr = std::shared_ptr<Texture>;
using pacman_ptr  = std::shared_ptr<Pacman>;

enum Tiles {
    TILE_WALL,
    TILE_POINT,
    TILE_BACKGROUND,
    TILE_ENEMY
};

void initializeEntities(std::array<tile_ptr , 4> environmentTiles,
                        std::array<tile_ptr , 6> fruitTiles,
                        LevelMap &levelMap,
                        std::list<entity_ptr> &environment,
                        std::list<entity_ptr> &fruits,
                        std::list<entity_ptr> &enemies,
                        pacman_ptr pacman) {

    for(int row = 0; row < levelMap.getRowCount(); row++) {
        for(int column = 0; column < levelMap.getColumnCount(); column++) {
            int x = Entity::WIDTH * column;
            int y = Entity::HEIGHT * row;

            switch(levelMap(column, row)) {
                case Field::FloorWithPoint:
                    environment.push_back(std::make_shared<StaticEntity>(StaticEntity(x, y, environmentTiles[TILE_POINT])));
                    break;
                case Field::Floor:
                    environment.push_back(std::make_shared<StaticEntity>(x, y, environmentTiles[TILE_BACKGROUND]));
                    break;
                case Field::Wall:
                    environment.push_back(std::make_shared<StaticEntity>(x, y, environmentTiles[TILE_WALL]));
                    break;
                case Field::Fruit:
                    fruits.push_back(std::make_shared<StaticEntity>(x, y, fruitTiles[rand() % 6]));
                    environment.push_back(std::make_shared<StaticEntity>(x, y, environmentTiles[TILE_BACKGROUND]));
                    break;
                case Field::Player:
                    pacman->setX(x);
                    pacman->setY(y);
                    environment.push_back(std::make_shared<StaticEntity>(x, y, environmentTiles[TILE_BACKGROUND]));
                    levelMap.setField(column, row, Field::FloorWithPoint);
                    break;
                case Field::Enemy:
                    environment.push_back(std::make_shared<StaticEntity>(x, y, environmentTiles[TILE_BACKGROUND]));
                    enemies.push_back(std::make_shared<Enemy>(x, y, environmentTiles[TILE_ENEMY]));
                    levelMap.setField(column, row, Field::FloorWithPoint);
                    break;
            }
        }
    }
}

int main(int argc, char** argv) {
    texture_ptr texture(new Texture("assets/tiles.png"));

    std::array<tile_ptr, 4> environmentTiles({
            std::make_shared<Tile>(texture, 0, 0, 32, 32),
            std::make_shared<Tile>(texture, 64, 0, 32, 32),
            std::make_shared<Tile>(texture, 64, 32, 32, 32),
            std::make_shared<Tile>(texture, 160, 0, 32, 32)
    });

    std::array<tile_ptr, 6> fruitTiles({
            std::make_shared<Tile>(texture, 0, 64, 32, 32),
            std::make_shared<Tile>(texture, 32, 64, 32, 32),
            std::make_shared<Tile>(texture, 64, 64, 32, 32),
            std::make_shared<Tile>(texture, 96, 64, 32, 32),
            std::make_shared<Tile>(texture, 128, 64, 32, 32),
            std::make_shared<Tile>(texture, 160, 64, 32, 32)
    });

    std::array<tile_ptr, 8> pacmanTiles({
            std::make_shared<Tile>(texture, 128 + 1, 32 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 224 + 1, 32 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 96 + 1, 32 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 192 + 1, 32 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 128 + 1, 0 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 224 + 1, 0 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 96 + 1, 0 + 1, 32 - 1, 32 - 1),
            std::make_shared<Tile>(texture, 192 + 1, 0 + 1, 32 - 1, 32 - 1)
    });

    pacman_ptr pacman = std::make_shared<Pacman>(0, 0, pacmanTiles);
    std::list<entity_ptr> enemies;
    std::list<entity_ptr> fruits;
    std::list<entity_ptr> environment;

    srand (time(NULL));

    // load level
    LevelMap levelMap = LevelMap::load("levels/default.lvl");

    // initialize entities
    initializeEntities(environmentTiles, fruitTiles, levelMap, environment, fruits, enemies, pacman);

    // initialize window
    int levelWidth = levelMap.getColumnCount() * Entity::WIDTH;
    int levelHeigth = levelMap.getRowCount() * Entity::HEIGHT;
    Window window("Punktefresser", levelWidth, levelHeigth);

    // initialize input handler
    InputHandler inputHandler;
    bool running = true;
    Timer timer;

    while (running) {
        // render
        for (entity_ptr entity : environment)
            window.renderEntity(entity);
        for (entity_ptr fruit : fruits)
            window.renderEntity(fruit);
        for (entity_ptr entity : enemies)
            window.renderEntity(entity);
        window.renderEntity(pacman);

        // input
        while (inputHandler.pollEvent()) {
            if (inputHandler.isKeyPressed(SDLK_w)) {
                pacman->setDirectionBuffer(Direction::Up);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                pacman->setDirectionBuffer(Direction::Down);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                pacman->setDirectionBuffer(Direction::Left);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                pacman->setDirectionBuffer(Direction::Right);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }

        // update
        pacman->tryApplyDirection(levelMap);
        pacman->move(levelMap);

        if (pacman->getX() % 32 == 0 && pacman->getY() % 32 == 0) {
            for (entity_ptr entity : environment) {
                if (entity->getX() == pacman->getX() && entity->getY() == pacman->getY()) {
                    environment.remove(entity);
                    environment.push_back(std::make_shared<StaticEntity>(pacman->getX(), pacman->getY(), environmentTiles[Tiles::TILE_BACKGROUND]));
                }
            }
        }

        window.update();
        timer.sleep(FRAME_SLEEP_TIME);
        timer.update();
    }

    return 0;
}
