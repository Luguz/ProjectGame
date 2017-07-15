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

enum class GameState {PLAY, EXIT};  // variable is "PLAY" when game runs

class MainGame{
public:
   MainGame();                      // constructor

   void GameLoop();
   void InitSystems();              // initialize basic Systems

private:

   GameState _GameState;


};




#endif //end of define(__GameProject__Graphics__)
