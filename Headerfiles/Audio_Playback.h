//
//    Game Project -> Space Strategy
//
//    Audio_Playback.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__Audio_Playback__
#define  __GameProject__Audio_Playback__

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "Player_World_Interaction.h"
#include "File_Manager.h"

class Audio_Playback{
public:
   // constructor
   Audio_Playback();

   // function to start audio functions
   void StartAudio();

   // string that contains the needed audiofile
   std::string strAudioFile;

private:

   // create pointer for music file
   Mix_Music *_ptrMusicPlayed = NULL;

   // function to manage Music
   void _PlayMusic(std::string strAudioFile);     // needs var for music type
};

#endif //end of define(__GameProject__Audio_Playback__)
