//
//    Game Project -> Space Strategy
//
//    MainGame.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Main_Game__
#define  __GameProject__Main_Game__

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "Screen_Graphics.h"
#include "Audio_Playback.h"
#include "World_Vectors.h"

enum class clGameState{PLAY, EXIT, PAUSE};  // class that contains diff. gamestates

class Main_Game{
   clGameState _clGameState;              // variable to control gamestatus
   World_Vectors PlayerHomeBase;
   Screen_Graphics BaseSDL;

   void _InputCheck();                    // monitors the input

   void _GameLoop();                       // decides if Game runs etc.
   void _InitSystems();                    // initialize basic Systems

   void _DrawGame();                       // draws game

public:

   Main_Game();                           // constructor

   void RunGame();                        // starts the game (the loop)
};




#endif //end of define(__GameProject__Main_Game__)
