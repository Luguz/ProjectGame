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
#include "Player_World_Interaction.h"
#include "Audio_Playback.h"
#include "Player_World_Variables.h"

enum class clGameState{PLAY, EXIT, PAUSE};  // class that contains diff. gamestates

class Main_Game{
public:
   Main_Game();                           // constructor

   void RunGame();                        // starts the game (the loop)

private:

   clGameState _clGameState;              // variable to control gamestatus

   void _InputCheck();                    // monitors the input

   void _GameLoop();                       // decides if Game runs etc.
   void _InitSystems();                    // initialize basic Systems

   void _DrawGame();                       // draws game

};




#endif //end of define(__GameProject__Main_Game__)
