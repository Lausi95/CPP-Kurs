#include <vector>
#include "stdafx.h"

const int X_SPEED = 15;
const int Y_SPEED = 10;

class Background : public Entity {
public:
    Background(float x, float y, Tile* tile) : Entity(x, y) {
        this->tile = tile;
    }
    Tile* getTile() {
        return tile;
    }
private:
    Tile* tile;
};

class BackgroundScroller {
public:
    BackgroundScroller(Tile* entity, int vx) {
        background1 = new Background(0, 0, entity);
        background2 = new Background(background1->getWidth(), 0, entity);
        this->vx = vx;
    }

    ~BackgroundScroller() {
        delete background1;
        delete background2;
    }

    void update() {
        background1->setX(background1->getX() - vx);
        background2->setX(background2->getX() - vx);
        resetIfOutOfScreen(background1);
        resetIfOutOfScreen(background2);
    }

    void render(Window* window) {
        window->renderEntity(background1);
        window->renderEntity(background2);
    }

private:
    Background* background1;
    Background* background2;
    int vx = 1;

    void resetIfOutOfScreen(Background* background) {
        if (background->getX() <= -background->getWidth()) {
            background->setX(background->getWidth());
        }
    }
};

class Shot : public Entity {
public:
    Shot(float x, float y, float movementX, float movementY) : Entity(x, y) {
        Texture* texture_spaceships = new Texture ("assets/spaceships.png");
        this->tile = new Tile(texture_spaceships, 32, 0, 32, 32);
        this->movementX = movementX;
        this->movementY = movementY;
    }

    Tile* getTile() {
        return tile;
    }

    void update() {
        setX(getX() + movementX);
        setY(getY() + movementY);
    }

    void checkCollision() {

    }

private:
    Tile* tile;
    float movementX;
    float movementY;
};

class SpaceShip : public Entity {
public:
    SpaceShip(float x, float y, Tile* tile) : Entity(x, y) {
        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

    void move(int moveX, int moveY, Window window) {

        //check bounds
        float newPositionX = getX() + moveX;
        float newPositionY = getY() + moveY;

        if(newPositionX + getWidth() <= window.getWidth() && newPositionX >= 0) {
            setX(newPositionX);
        }

        if(newPositionY + getHeight() <= window.getHeight() && newPositionY >= 0) {
            setY(newPositionY);
        }
    }

    virtual Shot* shoot() {
        Shot* shot = new Shot(getX(), getY(), X_SPEED, 0);
        return shot;
    }

private:
    Tile* tile;
};

class EnemySpaceShip : public SpaceShip {
public:
    EnemySpaceShip(float x, float y, Tile* tile) : SpaceShip(x, y, tile) {

    }

    void moveRandom(Window window) {

        bool moveX = (bool) (rand() % 2);
        bool moveY = (bool) (rand() % 2);

        if(moveX) {
            bool moveLeft = (bool) (rand() % 2);

            if(moveLeft) {
                move(-X_SPEED, 0, window);
            }
            else {
                move(X_SPEED, 0, window);
            }
        }

        if(moveY) {
            bool moveTop = (bool) (rand() % 2);

            if(moveTop) {
                move(0, -Y_SPEED, window);
            }
            else {
                move(0, Y_SPEED, window);
            }
        }
    }

    Shot* shoot() {
        Shot* shot = new Shot(getX(), getY(), X_SPEED, 0);
        return shot;
    }

private:

};

int main(int argc, char** argv) {

    srand (time(NULL));

    Window window("SpaceShipRace", 800, 600);

    Texture texture_background("assets/background.png");
    Texture texture_spaceships("assets/spaceships.png");
    Texture texture_stars1("assets/stars1.png");
    Texture texture_stars2("assets/stars2.png");
    Texture texture_stars3("assets/stars3.png");

    Tile tile_background(&texture_background, 0, 0, 1024, 800);
    Tile tile_spaceship(&texture_spaceships, 0, 32, 32, 32);
    Tile tile_enemy_spaceship(&texture_spaceships, 0, 224, 32, 32);
    Tile tile_stars1(&texture_stars1, 0, 0, 800, 600);
    Tile tile_stars2(&texture_stars2, 0, 0, 800, 600);
    Tile tile_stars3(&texture_stars3, 0, 0, 800, 600);

    Background background(0, 0, &tile_background);

    BackgroundScroller scroller1(&tile_stars1, 5);
    BackgroundScroller scroller2(&tile_stars2, 4);
    BackgroundScroller scroller3(&tile_stars3, 2);

    std::vector<BackgroundScroller*> backgroundScroller;
    backgroundScroller.push_back(&scroller1);
    backgroundScroller.push_back(&scroller2);
    backgroundScroller.push_back(&scroller3);

    SpaceShip ship(32, 300, &tile_spaceship);

    EnemySpaceShip enemyShip1(650, 100, &tile_enemy_spaceship);
    EnemySpaceShip enemyShip2(550, 200, &tile_enemy_spaceship);
    EnemySpaceShip enemyShip3(450, 300, &tile_enemy_spaceship);
    EnemySpaceShip enemyShip4(550, 400, &tile_enemy_spaceship);
    EnemySpaceShip enemyShip5(650, 500, &tile_enemy_spaceship);

    std::vector<EnemySpaceShip*> enemies;
    enemies.push_back(&enemyShip1);
    enemies.push_back(&enemyShip2);
    enemies.push_back(&enemyShip3);
    enemies.push_back(&enemyShip4);
    enemies.push_back(&enemyShip5);

    std::vector<Entity*> gameObjects;

    InputHandler inputHandler;
    bool running = true;
    Timer timer;

    const int MAX_CYCLES = 7;
    int cyclesToWaitBeforeUpdateMap = MAX_CYCLES;

    while (running) {

        if(--cyclesToWaitBeforeUpdateMap == -1) {
            cyclesToWaitBeforeUpdateMap = MAX_CYCLES;
        }

        // render entities
        window.renderEntity(&background);

        window.renderEntity(&ship);

        for(BackgroundScroller* scroller : backgroundScroller) {
            scroller->render(&window);
            scroller->update();
        }

        for(EnemySpaceShip* enemy : enemies) {
            window.renderEntity(enemy);
            if(cyclesToWaitBeforeUpdateMap == 0) {
                enemy->moveRandom(window);
            }
        }

        for(Entity* entity : gameObjects) {
            window.renderEntity(entity);
            if(Shot* shot = dynamic_cast<Shot*>(entity)) {
                shot->update();
            }
        }

        // input
        while (inputHandler.pollEvent()) {

            if (inputHandler.isKeyPressed(SDLK_w)) {
                ship.move(0, -Y_SPEED, window);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                ship.move(0, Y_SPEED, window);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                ship.move(-X_SPEED, 0, window);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                ship.move(X_SPEED, 0, window);
            }
            if (inputHandler.isKeyPressed(SDLK_SPACE)) {
                Shot* shot = ship.shoot();
                gameObjects.push_back((Entity*)shot);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

        window.update();
        timer.sleep(8);
        timer.update();
    }

    return 0;
}
