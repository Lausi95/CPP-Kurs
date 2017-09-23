#include "BackgroundMusic.h"

BackgroundMusic::BackgroundMusic(Codec codec, const char* file) {

    _file = file;

    switch (codec) {

        case MP3:
            _initFlags = MIX_INIT_MP3;
            break;

        default:
            _initFlags = MIX_INIT_MP3;
    }
}


bool BackgroundMusic::init() {

    SDL_Init(SDL_INIT_AUDIO);

    Mix_Init(_initFlags);

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
}


void BackgroundMusic::cleanUp() {

    Mix_FreeMusic(_music);
    Mix_CloseAudio();
}


void BackgroundMusic::start() {

    _music = Mix_LoadMUS(_file);
    Mix_PlayMusic(_music, -1);
}


void BackgroundMusic::stop() {
    Mix_HaltMusic();
}


void BackgroundMusic::restart() {
    stop();
    start();
}


void BackgroundMusic::pause() {
    Mix_PauseMusic();
}


void BackgroundMusic::resume() {
    Mix_ResumeMusic();
}