#include <Entity.h>
#include <stdafx.h>

const int FRAME_SLEEP_TIME = 8;

using Texture_SPTR = std::shared_ptr<Texture>;

enum Tiles {
    TILE_WALL,
    TILE_POINT,
    TILE_NORMAL_BACKGROUND,
    TILE_ENEMY
};

void initializeEntities(Tile* tilemap,
                        Tile* fruitTiles,
                        LevelMap &levelMap,
                        std::list<StaticEntity> &environment,
                        std::list<StaticEntity> &fruits,
                        std::list<Enemy> &enemies,
                        Pacman &pacman) {

    for(int row = 0; row < levelMap.getRowCount(); row++) {
        for(int column = 0; column < levelMap.getColumnCount(); column++) {
            int x = Entity::WIDTH * column;
            int y = Entity::HEIGHT * row;

            switch(levelMap(column, row)) {
                case Field::FloorWithPoint:
                    environment.push_back(StaticEntity(x, y, &tilemap[Tiles::TILE_POINT]));
                    break;
                case Field::Floor:
                    environment.push_back(StaticEntity(x, y, &tilemap[Tiles::TILE_NORMAL_BACKGROUND]));
                    break;
                case Field::Wall:
                    environment.push_back(StaticEntity(x, y, &tilemap[Tiles::TILE_WALL]));
                    break;
                case Field::Fruit:
                    fruits.push_back(StaticEntity(x, y, &fruitTiles[rand() % 6]));
                    environment.push_back(StaticEntity(x, y, &tilemap[Tiles::TILE_NORMAL_BACKGROUND]));
                    break;
                case Field::Player:
                    pacman.setX(x);
                    pacman.setY(y);
                    environment.push_back(StaticEntity(x, y, &tilemap[Tiles::TILE_NORMAL_BACKGROUND]));
                    levelMap.setField(column, row, Field::FloorWithPoint);
                    break;
                case Field::Enemy:
                    environment.push_back(StaticEntity(x, y, &tilemap[Tiles::TILE_NORMAL_BACKGROUND]));
                    enemies.push_back(Enemy(x, y, &tilemap[Tiles::TILE_ENEMY]));
                    levelMap.setField(column, row, Field::FloorWithPoint);
                    break;
            }
        }
    }
}

int main(int argc, char** argv) {
    Texture_SPTR texture(new Texture("assets/tiles.png"));

    Tile tilemap[] = {
            Tile(texture, 0, 0, 32, 32),
            Tile(texture, 64, 0, 32, 32),
            Tile(texture, 64, 32, 32, 32),
            Tile(texture, 160, 0, 32, 32)
    };

    Tile fruitTiles[] = {
            Tile(texture, 0, 64, 32, 32),
            Tile(texture, 32, 64, 32, 32),
            Tile(texture, 64, 64, 32, 32),
            Tile(texture, 96, 64, 32, 32),
            Tile(texture, 128, 64, 32, 32),
            Tile(texture, 160, 64, 32, 32)
    };

    PacmanTiles pacmanTiles = {
            new Tile(texture, 128+1, 32+1, 32-1, 32-1),
            new Tile(texture, 96+1, 32+1, 32-1, 32-1),
            new Tile(texture, 128+1, 0+1, 32-1, 32-1),
            new Tile(texture, 96+1, 0+1, 32-1, 32-1),

            new Tile(texture, 224+1, 32+1, 32-1, 32-1),
            new Tile(texture, 192+1, 32+1, 32-1, 32-1),
            new Tile(texture, 192+1, 0+1, 32-1, 32-1),
            new Tile(texture, 224+1, 0+1, 32-1, 32-1)
    };

    Pacman pacman(0, 0, &pacmanTiles);
    std::list<Enemy> enemies;
    std::list<StaticEntity> fruits;
    std::list<StaticEntity> environment;

    srand (time(NULL));

    // load level
    LevelMap levelMap = LevelMap::load("levels/default.lvl");

    // initialize entities
    initializeEntities(tilemap, fruitTiles, levelMap, environment, fruits, enemies, pacman);

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
        for (StaticEntity entity : environment)
            window.renderEntity(&entity);
        for (StaticEntity fruit : fruits)
            window.renderEntity(&fruit);
        for (Enemy entity : enemies)
            window.renderEntity(&entity);
        window.renderEntity(&pacman);

        // input
        while (inputHandler.pollEvent()) {
            if (inputHandler.isKeyPressed(SDLK_w)) {
                pacman.setDirectionBuffer(Direction::Up);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                pacman.setDirectionBuffer(Direction::Down);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                pacman.setDirectionBuffer(Direction::Left);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                pacman.setDirectionBuffer(Direction::Right);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }

        // update
        pacman.tryApplyDirection(levelMap);
        pacman.move(levelMap);

        if (pacman.getX() % 32 == 0 && pacman.getY() % 32 == 0) {
            for (StaticEntity entity : environment) {
                if (entity.getX() == pacman.getX() && entity.getY() == pacman.getY()) {
                    environment.remove(entity);
                    environment.push_back(StaticEntity(pacman.getX(), pacman.getY(), &tilemap[Tiles::TILE_NORMAL_BACKGROUND]));
                }
            }
        }

        window.update();
        timer.sleep(FRAME_SLEEP_TIME);
        timer.update();
    }

    return 0;
}
