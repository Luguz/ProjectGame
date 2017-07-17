//
//    Game Project -> Space Strategy
//
//    Audio.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Audio__
#define  __GameProject__Audio__

#include <string>
#include <stdio.h>
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

   Mix_Music *musicPlayed = NULL;
   // function to manage Music
   void _PlayMusic(std::string audioFile);            // needs var for music type
};

#endif //end of define(__GameProject__Audio__)
