//
//    Game Project -> Space Strategy
//
//    Audio.cpp
//    copyrights by Lukas Guz
//

#include "Audio.h"
#include "GameStructure.h"
#include "ResourceLinker.h"

//constructor
Audio::Audio():
   audioFile("STARTMUSIC"),
   _musicPlayed(NULL){

}

// starts the SDL audio functions
void Audio::StartAudio(){
   // initialize audio
   SDL_Init(SDL_INIT_AUDIO);
   if (SDL_Init(SDL_INIT_AUDIO != 0)){
      printf("error initializing Audio: %s\n", SDL_GetError());
   }
   // initialize SDL_mixer for audio
   if( Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) == -1){
      printf( "SDL_mixer could not initialize! SDL_mixer Error:%s\n"
         , Mix_GetError() );
   }

   _PlayMusic("STARTMUSIC");
}


// function to play the music in background
void Audio::_PlayMusic(std::string audioFile){

   // search for music in Resources
   ResourceLinker resourceLinker;
   resourceLinker.LoadResources("Audio",audioFile);
   printf("file path used %s\n",resourceLinker._filePath.c_str());

   // Load the Music specific musicfile
   _musicPlayed = Mix_LoadMUS("../Resources/Audio/Dark_Atmosphere13_Looped_24bit.wav");
   if(!_musicPlayed){
     printf( "Failed to load Audio(Music): %s\n", Mix_GetError());
  }

  // play the music forever (,-1) eq. zero on success
  if(Mix_PlayMusic(_musicPlayed, -1) == -1) {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
  }

  // stops music playback
  Mix_HaltMusic();
  Mix_FreeMusic(_musicPlayed);   // free the pointer of music
  _musicPlayed = NULL;           // to check if it is freed

}
