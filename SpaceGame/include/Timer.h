#ifndef SDL_GAME_TIMER_H
#define SDL_GAME_TIMER_H

#include <SDL2/SDL.h>
#include <ctime>

class Timer {
public:
    Timer();

    void update();
    float tslf();

    void sleep(Uint32 millis);
private:
    struct timespec time1;
    struct timespec time2;

    float timeSinceLastFrame;
};

#endif
