#ifndef GAME_SOUND_H
#define GAME_SOUND_H

#include <raylib-cpp.hpp>
#include <unistd.h>

class GameSound {
private:
    Music backgroundMusic;
    Music bulletSound;
    Music stepsSound;
    Music deadPlayerSound;
    Sound shootPlayerSound;
    Sound zombieSound;
    float timePlayedSound = 0.0f;
public:
    Sound playerScrum1;
    Sound playerScrum2;
    Sound playerScrum3;
    Sound playerScrum4;
    Sound playerScrum5;

    GameSound();

    ~GameSound();

    void PlayBgMusic(Music sound);
    void PlayWalkSounds(Music sound, bool isMove);
    void PlayIsDeadSounds(Music sound, bool isDeadPlayer);
    void PlayerShotSounds(Sound sound, bool isShoot);
    void ZombieSound(Sound sound);
    void PlayScreamSound(int random);
    /************************/
    /* getters and setters */
    /**********************/
    Music getBackgroundMusic() const;
    
    Music getStepSound() const;
    Music getDeadPlayerSound() const;
    Sound getPlayerShotSounds() const;
    Sound getZombieSound() const;
    float getTimePlayedSound();
    std::vector<Sound> getPlayerScreams() const;

    void setTimePlayedSound(float timePlayed);
    
};

#endif //GAME_SOUND_H
