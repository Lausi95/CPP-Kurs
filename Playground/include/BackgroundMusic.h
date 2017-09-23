#ifndef PLAYGROUND_MUSICPLAYER_H
#define PLAYGROUND_MUSICPLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

enum Codec {MP3};

class BackgroundMusic {

private:
    Mix_Music* _music;
    int _initFlags;
    const char* _file;

public:
    explicit BackgroundMusic(Codec codec, const char* file);

    void cleanUp();
    bool init();

    void start();
    void stop();
    void restart();

    void pause();
    void resume();

};


#endif //PLAYGROUND_MUSICPLAYER_H
