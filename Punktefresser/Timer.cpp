#include "Timer.h"

Timer::Timer() {
    clock_gettime(CLOCK_MONOTONIC, &time1);
}

void Timer::update() {
    clock_gettime(CLOCK_MONOTONIC, &time2);
    struct timespec diff;
    diff.tv_nsec = time2.tv_nsec - time1.tv_nsec;
    diff.tv_sec = time2.tv_sec - time1.tv_sec;
    timeSinceLastFrame = (float)diff.tv_sec + (float)diff.tv_nsec / 1000000000.0f;
    time1 = time2;
}

float Timer::tslf() {
    return timeSinceLastFrame;
}

void Timer::sleep(Uint32 millis) {
    SDL_Delay(millis);
}
