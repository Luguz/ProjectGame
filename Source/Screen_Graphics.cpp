//
//    Game Project -> Space Strategy
//
//    Screen_Graphics.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Screen_Graphics.h"

/****************** Constructors **********************************************/

// Standard-Constructor
Screen_Graphics::Screen_Graphics(){

}

// constructor to initialize the variables
Screen_Graphics::Screen_Graphics(int iScreenWidth, int iScreenHeight, int iSizeOfWorld, int iSizeOfTile):
   _ptrWindow(NULL), _ptrRenderer(NULL), _ptrSurface(NULL){

   // smalles unit on screen
   iTileSize = iSizeOfTile;    // size of Object to be drawn in X direction (pixel)
   iTile = 0;         // first place in world vector

   // set the WorldSize
   iWorldSize = iSizeOfWorld;

   // allow use of camera from camera class
   //PlayerCamera = Screen_Camera(iScreenWidth, iScreenHeight, iSizeOfWorld, iTileSize);
   // camera variables
   /*iCameraX = 0 ;                               // camera x position (init)
   iCameraY = 0 ;                               // camera y position (init)
   iCameraW = PlayerCamera.get_CameraWidth() ;  // camera width (const)
   iCameraH = PlayerCamera.get_CameraHeight();  // camera height (const)
   iCameraZ = PlayerCamera.get_CameraZoom();    // camera Zoom faktors*/

   // source variables
   Src.x = 0;			//Source set for x and y
   Src.y = 0;
   Src.w = 100;		//Soruce set for width and height
   Src.h = 100;

   // destination on screen variables  (init)
   Dest.x = 0;		   //Destination set for x and y
   Dest.y = 0;
   Dest.w = 50;		//Destination set for width and height
   Dest.h = 50;

}

/****************** Start SDL (Graphics) **************************************/

// function to start the basic SDL (Graphic) functionalities
void Screen_Graphics::StartSDL(int iScreenWidth, int iScreenHeight){

   // initialize everything
   SDL_Init(SDL_INIT_VIDEO);
   if (SDL_Init(SDL_INIT_VIDEO != 0)){
      printf("error initializing SDL: %s\n", SDL_GetError());
   }

   // create the window
   SDL_Window *_ptrWindow = SDL_CreateWindow("GameProject", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, iScreenWidth, iScreenHeight, SDL_WINDOW_SHOWN);
   if (!_ptrWindow){
      printf("error creating window: %s\n", SDL_GetError());
      SDL_Quit();
   }

   // disables screensaver
   void SDL_DisableScreenSaver(void);

   // create renderer
   _ptrRenderer = SDL_CreateRenderer(_ptrWindow,-1,SDL_RENDERER_ACCELERATED
      | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
   if(!_ptrRenderer){
      printf("error creating renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(_ptrWindow);
      SDL_Quit();
   }
}

/****************** Control the functionalities of SDL (Graphics) *************/

// combines and manages all Graphic functions
void Screen_Graphics::GraphicsControl(World_Vectors vecWorldVector, int iWorldSize,
   int iScreenHeight, int iScreenWidth, int iCameraEdgeState, int iCameraZoom,
   int iSelectPosX, int iSelectPosY){

   // Load Textures
   LoadTextures();

   // move Camera depending on iCameraEdgeState (see documentation depending variable)
   //PlayerCamera.move_Camera(iCameraEdgeState, iCameraZoom);

   // draws the World Surface of the chosen Vector
   DrawWorldSurface(vecWorldVector, iSelectPosX, iSelectPosY);

   // update window (a function by SDL)
   SDL_UpdateWindowSurface(_ptrWindow);

}

/****************** Draw the Graphics on Screen *******************************/

// Draws the surface out of Worldvector from Loaded Textures from LoadTextures
void Screen_Graphics::DrawWorldSurface(World_Vectors vecWorldVector, int iSelectPosX, int iSelectPosY){

// render background
int iRowPlace = 1;

do{

   do {
      // decide whats to be drawn on Screen
      //printf("%i\n",iTile );
      switch (vecWorldVector.get_vecWorldVectorTile(iTile)) {

         // draw nothing (other building will be drawn later)
         case 0:  //SDL_RenderCopy(_ptrRenderer, background, &Src, &Dest);
                  break;
         // draw background
         case 1:  SDL_RenderCopy(_ptrRenderer, background, &Src, &Dest);
                  break;
      }
      Dest.x = iTileSize*iRowPlace;
      iTile++;
      iRowPlace++;

   }while(iRowPlace % (iWorldSize+1) != 0);

   // reset Dest for x and y for next row
   Dest.y += iTileSize/2;
   //printf("iRow:%i Desty:%i",iRowPlace,Dest.y);
   Dest.x = 0;
   iRowPlace = 1;

}while(iTile <= iWorldSize*iWorldSize-1);

// selection field render
Dest.x = iSelectPosX;
Dest.y = iSelectPosY;
SDL_RenderCopy(_ptrRenderer, selectionField, &Src, &Dest);

// Render whats calculated by checking the WorldVector
SDL_RenderPresent(_ptrRenderer);
// reset the Start Postion on Screen
Dest.x = 0;
Dest.y = 0;
iTile = 0;

}

/****************** Load Textures in Game *************************************/

// Load Textures to use them later in DrawWorldSurface
void Screen_Graphics::LoadTextures(){

   // initialize loading of png's
   IMG_Init( IMG_INIT_PNG );
   // create SDL Textures to be filled
   _ptrSurface = IMG_Load("Resources/Textures/groundTile_NE.png");
   background	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   _ptrSurface = IMG_Load("Resources/Textures/selection.png");
   selectionField	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
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
