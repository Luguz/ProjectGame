//
//    Game Project -> Space Strategy
//
//    Graphics.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Graphics.h"


Graphics::Graphics():
   _screenWidth(500),
   _screenHeight(500),
   _window(NULL),
   _renderer(NULL),
   _surface(NULL){

}

void Graphics::StartSDL(){
   // initialize everything
   SDL_Init(SDL_INIT_VIDEO);
   if (SDL_Init(SDL_INIT_VIDEO != 0)){
      printf("error initializing SDL: %s\n", SDL_GetError());
   }

   // create the window
   SDL_Window *_window = SDL_CreateWindow("GameProject", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
   if (!_window){
      printf("error creating window: %s\n", SDL_GetError());
      SDL_Quit();
   }

   // disables screensaver
   void SDL_DisableScreenSaver(void);

   // create renderer
   _renderer = SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED
      |SDL_RENDERER_PRESENTVSYNC);
   if(!_renderer){
      printf("error creating renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(_window);
      SDL_Quit();
   }

}


void Graphics::_GraphicsControl(){


   // update window
   SDL_UpdateWindowSurface(_window);

}
