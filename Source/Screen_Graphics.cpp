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

   // Load Textures
   //LoadTextures();
   // start the creating of World based on World-Vector
   DrawWorldSurface();
   // update window
   SDL_UpdateWindowSurface(_ptrWindow);

}

// Load Textures to use them later in DrawWorldSurface
/*void Screen_Graphics::LoadTextures(){
   // create SDL Textures to be filled



}*/

// Draws the surface out of Worldvector from Loaded Textures from LoadTextures
void Screen_Graphics::DrawWorldSurface(){

   /*SDL_Texture    *background;
   _ptrSurface = IMG_Load("Resources/Textures/IsoGround.png");
   background	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   // running index
   int i = 0;

   // going through the vecWorldVector to draw World surface
   while(i < Player_World_Variables::iWorldsize){

      // check if 0 (nothing to render) is in the Worldvector
      if(Player_World_Variables::vecWorldVector[i] == 0){
         i++;
      }

      // if there is is somthing else render the object
      else{

         // Image from Source destination
         SDL_Rect Src;		//Source of image
         Src.x = 0;			//Source set for x and y
         Src.y = 0;
         Src.w = 100;		//Soruce set for width and height
         Src.h = 100;

         // Destination of the Image on Screen
         SDL_Rect Dest;		//Destination of Image
         Dest.x = 200;			//Destination set for x and y
         Dest.y = 200;
         Dest.w = 100;		//Destination set for width and height
         Dest.h = 100;

         Player_World_Variables::vecWorldVector
            [Player_World_Variables::iWorldsize];

         // finally rendering
         SDL_RenderCopy(_ptrRenderer, background, &Src ,&Dest);

         // running index +1
         i++;
         }
   }*/

}
