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

    setVolume(MIX_MAX_VOLUME);

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


void SoundSystem::setVolume(int volume) {

    _volumeBeforeMuted = volume;

    //volume for effects
    Mix_Volume(-1, volume);

    //volumne for music
    Mix_VolumeMusic(volume);

    if (volume > 0) {
        _muted = false;
    }
    else if (volume == 0) {
        _muted = true;
    }
}


void SoundSystem::reset() {

    if (! _initialized) return;

    cleanUp();
    init();
}


bool SoundSystem::isMuted() {
    return _muted;
}


void SoundSystem::mute(bool mute) {

    if (! _initialized) return;

    if(_volumeBeforeMuted != -1) {
        if(mute) {
            //dont set volume yet, just get the current volume
            _volumeBeforeMuted = Mix_Volume(-1, -1);

            //set volume of all channels to 0
            Mix_Volume(-1, 0);

            Mix_VolumeMusic(0);
            _muted = true;
        }
        else {
            Mix_Volume(-1, _volumeBeforeMuted);
            Mix_VolumeMusic(_volumeBeforeMuted);
            _muted = false;
        }
    }
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
