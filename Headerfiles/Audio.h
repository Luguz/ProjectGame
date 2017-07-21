//
//    Game Project -> Space Strategy
//
//    Audio.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__Audio__
#define  __GameProject__Audio__

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


class Audio{
public:
   // constructor
   Audio();

   // function to start audio functions
   void StartAudio();

   // string that contains the needed audiofile
   std::string audioFile;

private:

   // create pointer for music file
   Mix_Music *_musicPlayed = NULL;

   // function to manage Music
   void _PlayMusic(std::string audioFile);            // needs var for music type
};

#endif //end of define(__GameProject__Audio__)
