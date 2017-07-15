//
//    Game Project -> Space Strategy
//
//    Graphics.h
//
//    Graphics.h :: copyrights by Lukas Guz


#ifndef  __GameProject__Graphics__
#define  __GameProject__Graphics__

#include "MainGame.h"

#include <SDL2/SDL.h>
#include <stdio.h>

class Graphics{
public:
   Graphics();                      // constructor

   void SDLInt();                   // makes window etc. (SDL)
private:
   SDL_Window* win;

};




#endif //end of define(__GameProject__Graphics__)
