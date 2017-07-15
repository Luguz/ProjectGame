//
//    Game Project -> Space Strategy
//
//    MainGame.cpp
//
//    MainGame.cpp :: copyrights by Lukas Guz

#include "MainGame.h"
#include "Graphics.h"

// constructor
MainGame::MainGame():
   _GameState(GameState::PLAY)
   {

   };

// this loop is used by other functions to close the game
void GameLoop(){
   // functions that checks the Gamestate
   while (_GameState = GameState::PLAY){
      MainGame maingame;
      maingame.InitSystems();
   }
}

// initialize every important functions to run basic game
void InitSystems(){
   // start the window
   Graphics graphics;
   graphics.SDLInt();
}
