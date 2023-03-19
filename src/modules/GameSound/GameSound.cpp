#include "GameSound.h"

GameSound::GameSound() {
    backgroundMusic = LoadMusicStream("assets/sounds/background_music.mp3");
    stepsSound = LoadMusicStream("assets/sounds/player_steps_sound.mp3");
    deadPlayerSound = LoadMusicStream("assets/sounds/scrum_AAA.mp3");
    shootPlayerSound = LoadSound("assets/sounds/shoot_sound.mp3");
    zombieSound = LoadSound("assets/sounds/zombie_sound2.mp3");

    playerScrum1 = LoadSound("assets/sounds/playerScream/ne_nado.mp3");
    playerScrum2 = LoadSound("assets/sounds/playerScream/akukratno_no_silno.mp3");
    playerScrum3 = LoadSound("assets/sounds/playerScream/achivak_scream.mp3");
    playerScrum4 = LoadSound("assets/sounds/playerScream/wow_anime_sound.mp3");
    playerScrum5 = LoadSound("assets/sounds/playerScream/begi_ska_befi_scream.mp3");
    PlayMusicStream(this->backgroundMusic);
} 

GameSound::~GameSound() {
    this->backgroundMusic =  LoadMusicStream("assets/sounds/background_music.mp3");
    UnloadMusicStream(this->backgroundMusic);
}


void GameSound::PlayScreamSound(int random) {
  switch (random)
  {
    case 0:
      PlaySound(playerScrum1);
      break;
    case 1:
      PlaySound(playerScrum2);
      break;
    case 2:
      PlaySound(playerScrum3);
      break;
    case 3:
      PlaySound(playerScrum4);
      break;
    case 4:
      PlaySound(playerScrum5);
    break;
    default:
      break;
  }
}
void GameSound::PlayBgMusic(Music sound) {
  UpdateMusicStream(sound);
  PlayMusicStream(sound);
  timePlayedSound = (GetMusicTimePlayed(sound)/GetMusicTimeLength(sound));
  if (timePlayedSound > 1.0f) timePlayedSound = 1.0f;
}

void GameSound::PlayWalkSounds(Music sound, bool isMove) {
  if (isMove) {
    UpdateMusicStream(sound);
    PlayMusicStream(sound);
    timePlayedSound = (GetMusicTimePlayed(sound)/GetMusicTimeLength(sound));
    if (timePlayedSound > 1.0f) timePlayedSound = 1.0f;
  } else {
    StopMusicStream(sound);
  }
}

void GameSound::PlayIsDeadSounds(Music sound, bool isDeadPlayer) {
  if (isDeadPlayer) {
    UpdateMusicStream(sound);
    PlayMusicStream(sound);
    timePlayedSound = (GetMusicTimePlayed(sound)/GetMusicTimeLength(sound));
    if (timePlayedSound > 1.0f) timePlayedSound = 1.0f;
  } else {
    StopMusicStream(sound);
  }
}

void GameSound::PlayerShotSounds(Sound sound, bool isShoot) {
  if (isShoot == true) {
    PlaySound(sound);
  }
}

void GameSound::ZombieSound(Sound sound) {
  PlaySound(sound);
}

/************************/
/* getters and setters */
/**********************/
Music GameSound::getBackgroundMusic() const{
    return backgroundMusic;
}

Music GameSound::getStepSound() const {
    return stepsSound;
}
// void GameSound::setBackgroundMusic(Music music) const {
//     this->backgroundMusic = music;
// }

float GameSound::getTimePlayedSound() {
  return timePlayedSound;
}

void GameSound::setTimePlayedSound(float timePlayed) {
    this->timePlayedSound = timePlayed;
}

Music GameSound::getDeadPlayerSound() const {
  return deadPlayerSound;
}

Sound GameSound::getPlayerShotSounds() const {
  return shootPlayerSound;
}

Sound GameSound::getZombieSound() const {
  return zombieSound;
}
// void GameSound::Update(Music music, bool isMove) {
//   PlayBgMusic(music, isMove);
//   PlayWalkSounds(music, isMove);
// }