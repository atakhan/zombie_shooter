#ifndef GAME_SOUND_H
#define GAME_SOUND_H

#include <raylib-cpp.hpp>

class GameSound {
private:
    Music backgroundMusic;
    Music bulletSound;
    std::vector<Music> zombieSounds;
    std::vector<Music> PlayerSound;
    float timePlayedSound = 0.0f;
public:
    GameSound();

    ~GameSound();

    Music getBackgroundMusic() const;

    // void setBackgroundMusic(Music Music) const;

    float getTimePlayedSound();

    void setTimePlayedSound(float timePlayedSound);
    
};

#endif //GAME_SOUND_H
