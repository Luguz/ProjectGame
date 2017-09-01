//
//    Game Project -> Space Strategy
//
//    Main_Game.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Main_Game.h"

/************ Constructor *****************************************************/

/*                             Standard-Constructor                           */

Main_Game::Main_Game(): _clGameState(clGameState::PLAY){  // Gamestate = PLAY

/*                           Basic-Game-functionalities                       */

   // allow SDL functions (Graphics) via BaseSDL in Main_Game
   BaseSDL = Screen_Graphics();
   // allow SDL functions (Audio) via AudioSDL in Main_Game
   AudioSDL = Audio_Playback();

/*                        Game-variables                                      */

   iPlayerWorldSize = 1000;

}

/************ Starts the main Game functions **********************************/

// basic public start function -> used in main.cpp

void Main_Game::RunGame(){
   // initialize the basic game-functions
   _InitSystems();
   // starts game loop
   _GameLoop();
}

/************ Loop of the whole Game ******************************************/

// this loop is used by other functions to close the game
// let the important functions work as long game runs

void Main_Game::_GameLoop(){
   // functions that checks the Gamestate -> Loop
   while(_clGameState != clGameState::EXIT){
      // input check
      _InputCheck();
      // draw the game
      _DrawGame();
   }
   // Quit Game if Loop ends
   Mix_Quit();
   SDL_Quit();
}

/************ initialize Basic Game Systems ***********************************/

// initialize every important function/variable to run game

void Main_Game::_InitSystems(){

   // creates world surface for starting World
   PlayerHomeBase = World_Vectors(iPlayerWorldSize);

   // creates the Window
   BaseSDL.StartSDL();

   // starts Audio functions
   AudioSDL.StartAudio();

}

/************ input Check of Player *******************************************/

// checks the input from player

void Main_Game::_InputCheck(){
SDL_Event evnt;      // variable for events ( 1 = pending; 2 = none available)

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

/************ Start the graphics of the Game **********************************/

// draws the final game with help of Graphics.cpp

void Main_Game::_DrawGame(){
   // starts all functions for creating the graphics
   BaseSDL.GraphicsControl(PlayerHomeBase, iPlayerWorldSize);
}
