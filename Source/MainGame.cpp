//
//    Game Project -> Space Strategy
//
//    MainGame.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "MainGame.h"
#include "Graphics.h"
#include "GameStructure.h"
#include "Audio.h"


// constructor
MainGame::MainGame():
   _GameState(GameState::PLAY){

   }

// basic public start function -> used in main.cpp
void MainGame::RunGame(){
   // initialize the basic game-functions
   _InitSystems();
   // starts game loop
   _GameLoop();
}

// this loop is used by other functions to close the game
// let the important functions work as long game runs
void MainGame::_GameLoop(){
   // functions that checks the Gamestate
   while(_GameState != GameState::EXIT){
      // input check
      _InputCheck();
      // draw the game
      _DrawGame();
   }
   Mix_Quit();
   SDL_Quit();
}

// initialize every important function/variable to run game
void MainGame::_InitSystems(){
   // creates the Window
   Graphics graphics;
   graphics.StartSDL();

   // creates world surface
   GameStructure gamestructure;
   gamestructure.StartWorldCreation();

   // starts Audio functions
   Audio audio;
   audio.StartAudio();
}

// checks the input from player
void MainGame::_InputCheck(){
SDL_Event evnt;                 // variable for events ( 1 = pending; 2 = none available)

   // process inputs
   while (SDL_PollEvent(&evnt)) // while event true (=1)
   {
       switch (evnt.type) {
         // Quit game with close window button
         case SDL_QUIT:
            _GameState = GameState::EXIT;
            break;
         // take mousemotion
         case SDL_MOUSEMOTION:
            break;
         default:
            break;
       }
   }
}

// draws the final game with help of Graphics.cpp
void MainGame::_DrawGame(){
   // starts all functions for creating the graphics
   Graphics graphics;
   graphics._GraphicsControl();
}
