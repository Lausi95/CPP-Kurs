#include <World.h>
#include <Input.h>
#include <entities/SimpleEntity.h>
#include <entities/Player.h>
#include <state/Worlds.h>
#include <SoundSystem.h>
#include <MenuFactory.h>
#include <iostream>

Worlds currentWorld = WORLD_MENU;

void changeWorld(Worlds newWorld) {
    currentWorld = newWorld;
}

class Level : public World {

    Player* _player;
    Entity* _boundingEntity;
    Input*  _input;
    SoundSystem* _soundSystem;
    int _jumpSoundID;

public:
    Level(Camera* camera, const std::vector<Entity*>& entities, Player* player, Entity* boundingEntity, Input* input, SoundSystem* soundSystem) : World(camera, entities) {
        _player = player;
        _boundingEntity = boundingEntity;
        _input = input;
        _soundSystem = soundSystem;
    }

    void initialize() override {
        _soundSystem->removeAllEffects();
        _jumpSoundID = _soundSystem->addEffect("assets/soundeffects/Jump.wav");
    }

    void update(float dt) override {
        if (_input->isADown())
            _player->setVx(-1.0f);
        else if (_input->isDDown())
            _player->setVx(1.0f);
        else
            _player->setVx(0.0f);

        if (_input->isWDown() && _player->canJump()) {
            _player->jump();
            _soundSystem->playEffect(_jumpSoundID);
        }

        _player->update();

        if (_player->getBottom() >= _boundingEntity->getBottom()) {
            _player->setVy(0);
            _player->jumpSetEnabled(true);
            _player->setBottom(_boundingEntity->getBottom());
        } else {
            _player->addVy(0.05f);
        }

        if (_player->getLeft() < _boundingEntity->getLeft())
            _player->setLeft(0.0f);
        if (_player->getRight() > _boundingEntity->getRight())
            _player->setRight(_boundingEntity->getRight());

        lockOn(_player);
    }
};

Camera camera(800, 608, "You May Not Touch The Ground");
Input input;
SoundSystem soundSystem(MP3);

Texture skyTexture("assets/images/backgrounds/sky.png");
Tile skyTile(&skyTexture, 0, 0, 800, 608);
SimpleEntity skyEntity(&skyTile, 0, 0);

Texture playerBoyLeftTexture("assets/images/tiles/player_boy_left.png");
Tile    playerBoyLeftTile(&playerBoyLeftTexture, 0, 0, 32, 32);
Texture playerBoyRightTexture("assets/images/tiles/player_boy_right.png");
Tile    playerBoyRightTile(&playerBoyRightTexture, 0, 0, 32, 32);
std::array<Tile*, 2> playerTiles {&playerBoyRightTile, &playerBoyLeftTile};
Player player(playerTiles, 0, 0, 32, 32);

std::vector<Entity*> e {&skyEntity, &player};
Level world(&camera, e, &player, &skyEntity, &input, &soundSystem);

int main() {

    soundSystem.init();
    soundSystem.startMusic("assets/music/Spectra.mp3");

    MenuFactory* menuFactory = new MenuFactory();
    Menu menu = menuFactory->getMenu(&camera, &input, &soundSystem, &changeWorld);

    World* worlds[] {
        &menu,
        &world
    };

    do {
        input.update();
        Worlds world = currentWorld;

        if (!worlds[world]->initialized()) {
            worlds[world]->initialize();
            worlds[world]->setInitialized(true);
        }

        worlds[world]->update(1.0f /*Unit, as long as the time since last frame is not calculated*/);
        worlds[world]->draw();

        if (world != currentWorld) {
            worlds[currentWorld]->setInitialized(false);
        }
    } while (!input.quitTriggered());

    soundSystem.stopMusic();
    soundSystem.cleanUp();
}
