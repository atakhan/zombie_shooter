#include "GameSound.h";

GameSound::GameSound() {
    backgroundMusic = LoadMusicStream("assets/sounds/background_music.mp3");
    PlayMusicStream(this->backgroundMusic);
} 

GameSound::~GameSound() {
    this->backgroundMusic =  LoadMusicStream("assets/sounds/background_music.mp3");
    UnloadMusicStream(this->backgroundMusic);
}

Music GameSound::getBackgroundMusic() const{
    return backgroundMusic;
}
// void GameSound::setBackgroundMusic(Music music) const {
//     this->backgroundMusic = music;
// }

float GameSound::getTimePlayedSound() {
    return this->timePlayedSound;
}

void GameSound::setTimePlayedSound(float timePlayedSound) {
    this->timePlayedSound = timePlayedSound;
}