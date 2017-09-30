//
//    Game Project -> Space Strategy
//
//    NAMEHERE.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Screen_Textures.h"

//constructor
Screen_Textures::Screen_Textures(){

}


void Screen_Textures::get_Textures(){

// initialize loading of png's
IMG_Init( IMG_INIT_PNG );
// create SDL Textures to be filled
_ptrSurface = IMG_Load("Resources/Textures/groundTile_NE.png");
background	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
SDL_FreeSurface(_ptrSurface);

// error code if Texture can't be loaded
if (!background){
      printf("error when creating texture: %s\n", SDL_GetError());
      SDL_DestroyRenderer(_ptrRenderer);
      SDL_DestroyWindow(_ptrWindow);
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}
