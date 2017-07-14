//
//    Game Project -> Space Strategy
//
//    Graphics.cpp
//
//    Graphics.cpp :: copyrights by Lukas Guz

#include "Graphics.h"


void Graphics::SDLInt(){
   // Test SDL
   SDL_Init(SDL_INIT_EVERYTHING);

   SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480,
    SDL_WINDOW_SHOWN);

   SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);

	SDL_DestroyWindow(win);
	SDL_Quit();
}
