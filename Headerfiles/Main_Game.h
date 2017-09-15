//
//    Game Project -> Space Strategy
//
//    MainGame.h
//    copyrights by Lukas Guz, Felix Korthals
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

enum class clGameState{START, PLAY, EXIT, PAUSE};  // class that contains diff. gamestates

class Main_Game{

/************************ Classes to include in Main_Game *********************/

   // variable to control gamestatus (PLAY,PAUSE,etc.)
   clGameState _clGameState;

/*                             Base-Functionalities                           */

   // include graphic functionalities in Main_Game
   Screen_Graphics BaseSDL;
   // include audio functionalities in Main_Game
   Audio_Playback AudioSDL;
   // include file management functionalities in Main_Game
   File_Manager FileStream;


/*************************** Main_Game functions ******************************/

/*                            Game-Variable-Functions                         */

   // world creation of Player-Home-Base
   int iPlayerWorldSize;                  // size of the Player World
   World_Vectors PlayerHomeBase;          // main Player starting World

/*                            Graphic-Parameter                               */

   // Screen Resolution
   int iSelectedScreenWidth;        // Width
   int iSelectedScreenHeigth;       // Heigth
   // Camera Variables
   int iCameraEdgeState;            // camera on/in edge/corner? -> see documentation for variable info
   int iMousePosX;                  // position mouse in x
   int iMousePosY;                  // position mouse in y
   int iEdgeSize;                   // size of edge-area in which scrolling begins (for simpler use)

   // monitors the input (SDL_Event)
   void _InputCheck();

   // decides if Game runs etc. -> Loop
   void _GameLoop();
   // initialize basic Systems -> SDL (Video,Music)
   void _InitSystems();

   // draws game (Graphics)
   void _DrawGame();

/**************************** PUPLIC ******************************************/
public:

/******************************************************************************/

   // constructor
   Main_Game();

/*                            Start The Game!                                 */

   // starts the game -> Loop, init. Systems
   void RunGame();

};




#endif //end of define(__GameProject__Main_Game__)
