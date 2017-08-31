//
//    Game Project -> Space Strategy
//
//    Screen_Graphics.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Screen_Graphics.h"


Screen_Graphics::Screen_Graphics():
   _iScreenWidth(1000),
   _iScreenHeight(1000),
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
void Screen_Graphics::GraphicsControl(World_Vectors HomeBase){

   // Load Textures
   //LoadTextures();
   // start the creating of World based on World-Vector
   DrawWorldSurface(HomeBase);
   // update window (a function by SDL not written here)
   SDL_UpdateWindowSurface(_ptrWindow);

}

// Load Textures to use them later in DrawWorldSurface
void Screen_Graphics::LoadTextures(){

   // create SDL Textures to be filled
   _ptrSurface = IMG_Load("Resources/Textures/ground.jpg");
   background	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   if (!background){
         printf("error when creating texture: %s\n", SDL_GetError());
         SDL_DestroyRenderer(_ptrRenderer);
         SDL_DestroyWindow(_ptrWindow);
         SDL_Quit();
         exit(EXIT_FAILURE);
      }
}

// Draws the surface out of Worldvector from Loaded Textures from LoadTextures
void Screen_Graphics::DrawWorldSurface(World_Vectors HomeBase){
   printf("DrawWorldSurface wird aufgerufen");
   //return;
   printf("World vector created?:%i\n",HomeBase.get_vecWorldVector(21));
   // Image from Source destination
   SDL_Rect Src;		//Source of image
   Src.x = 0;			//Source set for x and y
   Src.y = 0;
   Src.w = 100;		//Soruce set for width and height
   Src.h = 100;

   // Destination of the Image on Screen
   SDL_Rect Dest;		//Destination of Image
   //Dest.x = 0;			//Destination set for x and y
   //Dest.y = 0;
   Dest.w = 100;		//Destination set for width and height
   Dest.h = 100;


   int ObjectSize = 100;
   int i = 0;
   int DestPosX = 0;
   int DestPosY = 0;

   while(i < 10000){

      if(DestPosX < 10 && Dest.y <= 200){
         Dest.x = DestPosX*ObjectSize;
         DestPosX++;
         //printf("-x%i",Dest.x);
         //printf("-y%i",Dest.y);
      }

      if(DestPosX == 10){
         DestPosX = 0;
         DestPosY += 100;
         Dest.y += 100;
         //printf("Debug\n");
      }

      i++;
      SDL_RenderCopy(_ptrRenderer, background, &Src, &Dest);
   }

   SDL_RenderPresent(_ptrRenderer);
   Dest.y= 0;
}
