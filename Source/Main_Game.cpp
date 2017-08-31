//
//    Game Project -> Space Strategy
//
//    Main_Game.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Main_Game.h"

// constructor
Main_Game::Main_Game():
   _clGameState(clGameState::PLAY){

   }

// basic public start function -> used in main.cpp
void Main_Game::RunGame(){
   // initialize the basic game-functions
   _InitSystems();
   // starts game loop
   _GameLoop();
}

// this loop is used by other functions to close the game
// let the important functions work as long game runs
void Main_Game::_GameLoop(){
   // functions that checks the Gamestate
   while(_clGameState != clGameState::EXIT){
      // input check
      _InputCheck();
      // draw the game
      _DrawGame();
   }
   Mix_Quit();
   SDL_Quit();
}

// initialize every important function/variable to run game
void Main_Game::_InitSystems(){
   // creates the Window
   BaseSDL = Screen_Graphics();
   BaseSDL.StartSDL();
   // creates world surface for starting World (watch in class for parameter discribtion)
   PlayerHomeBase = World_Vectors(1000,1);
   //world_vectors.create_vecWorldVector("PlayerHomeBase",100, 1);

   // starts Audio functions
   Audio_Playback audio_playback;
   audio_playback.StartAudio();
}

// checks the input from player
void Main_Game::_InputCheck(){
SDL_Event evnt;                 // variable for events ( 1 = pending; 2 = none available)

   // process inputs
   while (SDL_PollEvent(&evnt)) // while event true (=1)
   {
       switch (evnt.type) {
         // Quit game with close window button
         case SDL_QUIT:
            _clGameState = clGameState::EXIT;
            break;
         // take mousemotion
         case SDL_MOUSEMOTION:
            break;
         case SDLK_ESCAPE:
            SDL_Quit();
         default:
            break;
       }
   }
}

// draws the final game with help of Graphics.cpp
void Main_Game::_DrawGame(){
   // starts all functions for creating the graphics
   BaseSDL.GraphicsControl(PlayerHomeBase);
}
