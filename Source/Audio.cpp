//
//    Game Project -> Space Strategy
//
//    Audio.cpp
//    copyrights by Lukas Guz
//

#include "Audio.h"
#include "GameStructure.h"
#include "RessourceLinker.h"

//constructor
Audio::Audio():
   audioFile("STARTMUSIC"){

}

// starts the SDL audio functions
void Audio::StartAudio(){
   // initialize audio
   SDL_Init(SDL_INIT_AUDIO);
   if (SDL_Init(SDL_INIT_AUDIO != 0)){
      printf("error initializing Audio: %s\n", SDL_GetError());
   }
   // initialize SDL_mixer for audio
   if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
      printf( "SDL_mixer could not initialize! SDL_mixer Error:%s\n"
         , Mix_GetError() );
   }
   _PlayMusic("STARTMUSIC");
}

void Audio::_PlayMusic(std::string audioFile){

   // changes music that plays
   //RessourceLinker ressourceLinker;
   //ressourceLinker.LoadResources("Audio",audioFile);

   // Load the Music specific musicfile
   musicPlayed = Mix_LoadMUS("Resources/Audio/Dark _Atmosphere13_Looped_24bit.wav");
   if( musicPlayed == NULL ){
     printf( "Failed to load Audio(Music): %s\n", Mix_GetError() );
  }
  // play the music
  Mix_PlayMusic( musicPlayed, 1);
  // free the music (is a pointer)
  Mix_FreeMusic( musicPlayed );
    musicPlayed = NULL;
}
