#include <iostream>
#include "SoundSystem.h"

SoundSystem::SoundSystem(Codec codec) {

    switch (codec) {

        case MP3:
            _initFlags = MIX_INIT_MP3;
            break;

        default:
            _initFlags = MIX_INIT_MP3;
    }
}


bool SoundSystem::init() {

    SDL_Init(SDL_INIT_AUDIO);

    Mix_Init(_initFlags);

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);

    Mix_AllocateChannels(500);

    _initialized = true;
}


void SoundSystem::cleanUp() {

    if (! _initialized) return;

    Mix_FreeMusic(_music);

    for(auto& chunk: _chunks) {
        Mix_FreeChunk(&chunk);
    }

    _chunks.clear();

    Mix_CloseAudio();

    _initialized = false;
}


void SoundSystem::reset() {

    if (! _initialized) return;

    cleanUp();
    init();
}


void SoundSystem::startMusic(char* file) {

    if (! _initialized) return;

    _musicFile = file;
    _music = Mix_LoadMUS(file);
    Mix_PlayMusic(_music, -1);
}


void SoundSystem::stopMusic() {

    if (! _initialized) return;

    Mix_HaltMusic();
}


void SoundSystem::restartMusic() {

    if (! _initialized) return;

    stopMusic();
    startMusic(_musicFile);
}


void SoundSystem::pauseMusic() {

    if (! _initialized) return;

    Mix_PauseMusic();
}


void SoundSystem::resumeMusic() {

    if (! _initialized) return;

    Mix_ResumeMusic();
}


void SoundSystem::playEffect(int id) {

    if (! _initialized) return;

    Mix_PlayChannel(-1, &_chunks.at(id), 0);
}


int SoundSystem::addEffect(char *file) {

    if (! _initialized) return -1;

    _chunks.push_back(*Mix_LoadWAV(file));

    //return new position as index
    return (int) (_chunks.size() - 1);
}

void SoundSystem::removeAllEffects() {

    if (! _initialized) return;

    _chunks.clear();
}
