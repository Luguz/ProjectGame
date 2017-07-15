//
//    Game Project -> Space Strategy
//
//    Graphics.cpp
//
//    Graphics.cpp :: copyrights by Lukas Guz

#include "Graphics.h"

Graphics::Graphics(){

}

void SDLInt(){
   // Test SDL
   SDL_Init(SDL_INIT_EVERYTHING);

   SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480,
    SDL_WINDOW_SHOWN);

   printf("Game-window loaded");
   SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);

}
