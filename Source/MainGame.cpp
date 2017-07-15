//
//    Game Project -> Space Strategy
//
//    MainGame.cpp
//
//    MainGame.cpp :: copyrights by Lukas Guz

#include "MainGame.h"
#include "Graphics.h"
#include <SDL2/SDL.h>

// constructor
MainGame::MainGame(){

   }

// this loop is used by other functions to close the game
void MainGame::GameLoop(){
   // functions that checks the Gamestate
   if (MainGame::pGameState == MainGame::GameState::PLAY){
      MainGame maingame;
      maingame.InitSystems();
   }else{
      SDL_Quit();
   }
}

// initialize every important functions to run basic game
void MainGame::InitSystems(){
   // start the window
   Graphics graphics;
   graphics.SDLInt();
}
