#ifndef PLAYGROUND_MUSICPLAYER_H
#define PLAYGROUND_MUSICPLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

using namespace std;

enum Codec {MP3};
const int VOLUME = 20;

class SoundSystem {

private:
    Mix_Music* _music;
    char* _musicFile;
    vector<Mix_Chunk> _chunks;
    int _initFlags;
    bool _initialized = false;

    int _volumeBeforeMuted = -1;
    bool _muted;

public:
    explicit SoundSystem(Codec codec);
    ~SoundSystem() {
        cleanUp();
    }

    void cleanUp();
    bool init();
    void reset();

    void setVolume(int volume);
    bool isMuted();
    void mute(bool mute);

    /* FOR MUSIC */
    void startMusic(char* file);
    void stopMusic();
    void restartMusic();

    void pauseMusic();
    void resumeMusic();

    /* FOR SOUND EFFECTS */
    int addEffect(char* file);
    void playEffect(int id);
    void removeAllEffects();

};


#endif //PLAYGROUND_MUSICPLAYER_H
