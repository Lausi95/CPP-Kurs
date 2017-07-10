#include <list>
#include <stdafx.h>

#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define FRAME_SLEEP_TIME 5

Texture mainTexture("assets/tiles.png");

Tile tilePlayerLookingTopMouthOpen(&mainTexture, 128+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingBotMouthOpen(&mainTexture, 96+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingLeftMouthOpen(&mainTexture, 128+1, 0+1, 32-1, 32-1);
Tile tilePlayerLookingRightMouthOpen(&mainTexture, 96+1, 0+1, 32-1, 32-1);

Tile tilePlayerLookingTopMouthClosed(&mainTexture, 224+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingBotMouthClosed(&mainTexture, 192+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingLeftMouthClosed(&mainTexture, 224+1, 0+1, 32-1, 32-1);
Tile tilePlayerLookingRightMouthClosed(&mainTexture, 192+1, 0+1, 32-1, 32-1);

Tile tileEnemy(&mainTexture, 160, 0, 32, 32);

Tile tileFruitBanana(&mainTexture, 0, 64, 32, 32);
Tile tileFruitPeach(&mainTexture, 32, 64, 32, 32);
Tile tileFruitGrapes(&mainTexture, 64, 64, 32, 32);
Tile tileFruitApple(&mainTexture, 96, 64, 32, 32);
Tile tileFruitMelon(&mainTexture, 128, 64, 32, 32);
Tile tileFruitPineapple(&mainTexture, 160, 64, 32, 32);
Tile fruitTiles[] = {tileFruitBanana, tileFruitPeach, tileFruitGrapes, tileFruitApple, tileFruitMelon, tileFruitPineapple};

Tile tileWall(&mainTexture, 0, 0, 32, 32);

Tile tilePoint(&mainTexture, 64, 0, 32, 32);
Tile tileNormalBackground(&mainTexture, 64, 32, 32, 32);

PacmanTiles pacmanTiles = {
        &tilePlayerLookingTopMouthOpen,
        &tilePlayerLookingTopMouthClosed,
        &tilePlayerLookingBotMouthOpen,
        &tilePlayerLookingBotMouthClosed,
        &tilePlayerLookingLeftMouthOpen,
        &tilePlayerLookingLeftMouthClosed,
        &tilePlayerLookingRightMouthOpen,
        &tilePlayerLookingRightMouthClosed
};

Pacman pacman(0, 0, &pacmanTiles);

std::list<Enemy> enemies;
std::list<StaticEntity> fruits;
std::list<StaticEntity> environment;

void initializeEntities(LevelMap levelMap) {
    for(int row = 0; row < levelMap.getRowCount(); row++) {
        for(int column = 0; column < levelMap.getColumnCount(); column++) {
            int x = TILE_WIDTH * column;
            int y = TILE_HEIGHT * row;

            switch(levelMap(column, row)) {
                case Field::FloorWithPoint:
                    environment.push_back(StaticEntity(x, y, &tilePoint));
                    break;
                case Field::Floor:
                    environment.push_back(StaticEntity(x, y, &tileNormalBackground));
                    break;
                case Field::Wall:
                    environment.push_back(StaticEntity(x, y, &tileWall));
                    break;
                case Field::Fruit:
                    fruits.push_back(StaticEntity(x, y, &fruitTiles[rand() % 6]));
                    environment.push_back(StaticEntity(x, y, &tileNormalBackground));
                    break;
                case Field::Player:
                    pacman.setX(x);
                    pacman.setY(y);
                    environment.push_back(StaticEntity(x, y, &tileNormalBackground));
                    levelMap.setField(column, row, Field::FloorWithPoint);
                    break;
                case Field::Enemy:
                    environment.push_back(StaticEntity(x, y, &tileNormalBackground));
                    enemies.push_back(Enemy(x, y, &tileEnemy));
                    levelMap.setField(column, row, Field::FloorWithPoint);
                    break;
            }
        }
    }
}

int main(int argc, char** argv) {
    srand (time(NULL));

    // load level
    LevelMap levelMap = LevelMap::load("levels/default.lvl");

    // initialize entities
    initializeEntities(levelMap);

    // initialize window
    int levelWidth = levelMap.getColumnCount() * TILE_WIDTH;
    int levelHeigth = levelMap.getRowCount() * TILE_HEIGHT;
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
                    environment.push_back(StaticEntity(pacman.getX(), pacman.getY(), &tileNormalBackground));
                }
            }
        }

        window.update();
        timer.sleep(FRAME_SLEEP_TIME);
        timer.update();
    }

    return 0;
}
