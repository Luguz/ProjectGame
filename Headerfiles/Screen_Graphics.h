//
//    Game Project -> Space Strategy
//
//    Screen_Graphics.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Graphics__
#define  __GameProject__Graphics__

#include <SDL2/SDL.h>         // basic SDL functions
#include <SDL2/SDL_image.h>   // for Loading Images
#include <stdio.h>
#include <string>

#include "World_Vectors.h"

class Screen_Graphics{
   // window related variables
   SDL_Window        *_ptrWindow        ;
   SDL_Renderer      *_ptrRenderer      ;
   SDL_Surface       *_ptrSurface       ;
   int               _iScreenWidth      ;
   int               _iScreenHeight     ;
   // Load Textures from Surface needed by DrawWorldSurface
   void LoadTextures();

   // draw the World on Screen out of vecWorldVector
   void DrawWorldSurface(World_Vectors);

   SDL_Texture    *background;

public:
   // constructor
   Screen_Graphics();

   // starts basic SDL instances
   void StartSDL();

   // manages graphic-functions(SDL) and changes
   void GraphicsControl(World_Vectors);

};




#endif //end of define(__GameProject__Graphics__)
