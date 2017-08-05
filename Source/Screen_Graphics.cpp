//
//    Game Project -> Space Strategy
//
//    Screen_Graphics.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Screen_Graphics.h"


Screen_Graphics::Screen_Graphics():
   _iScreenWidth(500),
   _iScreenHeight(500),
   _ptrWindow(NULL),
   _ptrRenderer(NULL),
   _ptrSurface(NULL){

}

void Screen_Graphics::StartSDL(){
   // initialize everything
   SDL_Init(SDL_INIT_VIDEO);
   if (SDL_Init(SDL_INIT_VIDEO != 0)){
      printf("error initializing SDL: %s\n", SDL_GetError());
   }

   // create the window
   SDL_Window *_ptrWindow = SDL_CreateWindow("GameProject", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, _iScreenWidth, _iScreenHeight, SDL_WINDOW_SHOWN);
   if (!_ptrWindow){
      printf("error creating window: %s\n", SDL_GetError());
      SDL_Quit();
   }

   // disables screensaver
   void SDL_DisableScreenSaver(void);

   // create renderer
   _ptrRenderer = SDL_CreateRenderer(_ptrWindow,-1,SDL_RENDERER_ACCELERATED
      |SDL_RENDERER_PRESENTVSYNC);
   if(!_ptrRenderer){
      printf("error creating renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(_ptrWindow);
      SDL_Quit();
   }

}

// combines and manages all Graphic functions
void Screen_Graphics::GraphicsControl(){

   // start the creating of World based on World-Vector
   DrawWorldSurface();
   // update window
   SDL_UpdateWindowSurface(_ptrWindow);

}

//
void Screen_Graphics::DrawWorldSurface(){
/*
   // running index
   int i = 0;

   // going through the _worldVector to draw World surface
   while(i < Player_World_Variables::iWorldsize){

      Player_World_Variables::vecWorldVector[i];
      i++;
   }
*/

}
