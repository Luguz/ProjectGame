//
//    Game Project -> Space Strategy
//
//    Screen_Graphics.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Screen_Graphics.h"

/****************** Constructors **********************************************/

// constructor to initialize the variables
Screen_Graphics::Screen_Graphics():
   _iScreenWidth(1000), _iScreenHeight(1000), _ptrWindow(NULL),
   _ptrRenderer(NULL), _ptrSurface(NULL){

      Src.x = 0;			//Source set for x and y
      Src.y = 0;
      Src.w = 100;		//Soruce set for width and height
      Src.h = 100;

      Dest.x = 0;		   //Destination set for x and y
      Dest.y = 0;
      Dest.w = 100;		//Destination set for width and height
      Dest.h = 100;

}

/****************** Start SDL (Graphics) **************************************/

// function to start the basic SDL (Graphic) functionalities
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

/****************** Control the functionalities of SDL (Graphics) *************/

// combines and manages all Graphic functions
void Screen_Graphics::GraphicsControl(World_Vectors WorldVector, int iWorldSize){

   // Load Textures
   LoadTextures();

   // draws the World Surface of the chosen Vector
   DrawWorldSurface(WorldVector, iWorldSize);

   // update window (a function by SDL)
   SDL_UpdateWindowSurface(_ptrWindow);

}

/****************** Draw the Graphics on Screen *******************************/

// Draws the surface out of Worldvector from Loaded Textures from LoadTextures
void Screen_Graphics::DrawWorldSurface(World_Vectors WorldVector, int iWorldSize){

   // basic variables to realize drawing
   int ObjectSize = 100;   // size of the Object to be drawn
   int i = 0;              // running index
   int DestPosX = 0;       // postion of Object on Screen in X-Direction
   int DestPosY = 0;       // postion of Object on Screen in Y-Direction


   // main function to draw the game
   // (done/checked for every postion in WorldVector)

   while(i < 10000){

      if(DestPosX < 10 && Dest.y <= 200){
         Dest.x = DestPosX*ObjectSize;
         DestPosX++;
      }

      if(DestPosX == 10){
         DestPosX = 0;
         DestPosY += 100;
         Dest.y += 100;
      }

      // next postion on WorldVector
      i++;
      // put new "Screen-Graphics-State" in Renderer
      SDL_RenderCopy(_ptrRenderer, background, &Src, &Dest);
   }

   // Render whats calculated by checking the WorldVector
   SDL_RenderPresent(_ptrRenderer);
   // reset the Start Postion on Screen
   Dest.x = 0;
   Dest.y = 0;
}

/****************** Load Textures in Game *************************************/

// Load Textures to use them later in DrawWorldSurface
void Screen_Graphics::LoadTextures(){

   // create SDL Textures to be filled
   _ptrSurface = IMG_Load("Resources/Textures/ground.jpg");
   background	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   // error code if Texture can't be loaded
   if (!background){
         printf("error when creating texture: %s\n", SDL_GetError());
         SDL_DestroyRenderer(_ptrRenderer);
         SDL_DestroyWindow(_ptrWindow);
         SDL_Quit();
         exit(EXIT_FAILURE);
      }
}
