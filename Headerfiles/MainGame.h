//
//    Game Project -> Space Strategy
//
//    Graphics.h
//
//    Graphics.h :: copyrights by Lukas Guz


#ifndef  __GameProject__MainGame__
#define  __GameProject__MainGame__

#include <SDL2/SDL.h>
#include <stdio.h>

class MainGame{
public:
   MainGame();                              // constructor

   enum GameState {PLAY, EXIT, PAUSE};
   static const GameState pGameState = PLAY;

   void GameLoop();                        // decides if Game runs etc.
   void InitSystems();                     // initialize basic Systems

private:


};




#endif //end of define(__GameProject__Graphics__)
