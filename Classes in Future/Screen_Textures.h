//
//    Game Project -> Space Strategy
//
//    NAMEHERE.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__Screen_Textures__
#define  __GameProject__Screen_Textures__

#include <SDL2/SDL.h>         // basic SDL functions
#include <SDL2/SDL_image.h>   // for Loading Images
#include <stdio.h>            // printf

class Screen_Textures{

   int iTextureAngle;         // here 45° for iso
   int iTextureSize;          // size of the Textures (object/building)


public:
   //constructor for texture-loading
   Screen_Textures();

   void get_Textures();

};

#endif //end of define(__GameProject__Screen_Textures__)
