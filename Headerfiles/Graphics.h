//
//    Game Project -> Space Strategy
//
//    Graphics.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Graphics__
#define  __GameProject__Graphics__

#include "MainGame.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

class Graphics{
public:
   // constructor
   Graphics();

   // starts basic SDL instances
   void StartSDL();

   // manages graphic-functions(SDL) and changes
   void _GraphicsControl();

private:
   // window related variables
   SDL_Window        *_window          ;
   SDL_Renderer      *_renderer        ;
   SDL_Surface       *_surface         ;
   int               _screenWidth      ;
   int               _screenHeight     ;

};




#endif //end of define(__GameProject__Graphics__)
