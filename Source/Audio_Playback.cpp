//
//    Game Project -> Space Strategy
//
//    Audio_Playback.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Audio_Playback.h"


//constructor
Audio_Playback::Audio_Playback():
   strAudioFile(""),
   _ptrMusicPlayed(NULL){

}

// starts the SDL audio functions
void Audio_Playback::StartAudio(){
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

   // Starts Music in Background
   _PlayMusic("STARTMUSIC");
}


// function to play the music in background
void Audio_Playback::_PlayMusic(std::string strAudioFile){

   // search for music in Resources
   file_manager.LinkResources("Audio",strAudioFile);
   //printf("%s\n",File_Manager::strFilePath.c_str());

   // Load the Music specific musicfile
   _ptrMusicPlayed = Mix_LoadMUS("Resources/Audio/game_music_0.ogg");
   if(!_ptrMusicPlayed){
      //file_manager.WriteErrorLog(Mix_GetError());
   }

  // play the music forever (,-1) eq. zero on success
  if(Mix_PlayMusic(_ptrMusicPlayed, -1) == -1) {
     //file_manager.WriteErrorLog(Mix_GetError());
  }
}
