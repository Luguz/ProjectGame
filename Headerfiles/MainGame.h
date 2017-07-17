//
//    Game Project -> Space Strategy
//
//    MainGame.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__MainGame__
#define  __GameProject__MainGame__

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

enum class GameState{PLAY, EXIT, PAUSE};  // class that contains diff. gamestates

class MainGame{
public:
   MainGame();                            // constructor

   void RunGame();                        // starts the game (the loop)

private:

   GameState _GameState;                  // variable to control gamestatus

   void _GameLoop();                       // decides if Game runs etc.
   void _InitSystems();                    // initialize basic Systems

   void _InputCheck();                     // monitors the input

   void _DrawGame();                       // draws game

};




#endif //end of define(__GameProject__Graphics__)
