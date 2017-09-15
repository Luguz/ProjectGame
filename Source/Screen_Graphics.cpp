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
Screen_Graphics::Screen_Graphics(int iScreenWidth, int iScreenHeight):
    _ptrWindow(NULL), _ptrRenderer(NULL), _ptrSurface(NULL){

      // allow use of camera from camera class
      PlayerCamera = Screen_Camera(100, 100, 1, 1, iScreenWidth, iScreenHeight);
      // camera variables
      iCameraX = 0 ;                               // camera x position init.
      iCameraY = 0 ;                               // camera y position init.
      iCameraW = PlayerCamera.get_CameraWidth() ;  // camera width (const)
      iCameraH = PlayerCamera.get_CameraHeight();  // camera height (const)

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
   int iScreenHeight, int iScreenWidth, int iCameraEdgeState){

   // Load Textures
   LoadTextures();

   // move Camera depending on iCameraEdgeState (see documentation depending variable)
   PlayerCamera.move_Camera(iCameraEdgeState);

   // draws the World Surface of the chosen Vector
   DrawWorldSurface(vecWorldVector, iWorldSize, iScreenHeight ,iScreenWidth, iCameraEdgeState);

   // update window (a function by SDL)
   SDL_UpdateWindowSurface(_ptrWindow);

}

/****************** Draw the Graphics on Screen *******************************/

// Draws the surface out of Worldvector from Loaded Textures from LoadTextures
void Screen_Graphics::DrawWorldSurface(World_Vectors vecWorldVector, int iWorldSize,
   int iScreenHeight, int iScreenWidth, int iCameraEdgeState){

   // basic variables to realize drawing (here later texture class)
   int iObjectSize = 100;   // size of Object to be drawn in X direction
   //int iObjectSizeY = 100;  // size of Object to be drawn in Y direction

   // running indexes
   int i = 0;           // running through the size of iWorldsize
   int j = 1;           // limits/determines the number of numbers in a row
   int h = 0;           // running index for going through the number of numbers in row

   int iNumberTiles = vecWorldVector.get_vecWorldVectorSize(); // actual number of Fields in WorldVector

   // functions and variable set depending on camera positon:
   int iCameraX = PlayerCamera.get_CameraPositionX();
   int iCameraY = PlayerCamera.get_CameraPositionY();

   // set i,j,h depending on camera position (first row to draw; i changes j,h later)
   /*do{
      i = iCameraY;  // first row to draw (i determines which row from World_Vector will be read)
      j = i+1;
      h =
   }*/


   //Dest.x = ((iScreenWidth/2) - (iObjectSize/2));   // set Dest.x for placement of first tile

   // main function to draw the game
   // (done/checked for every postion in WorldVector)

   for(i = 0; i < iWorldSize*2+3; i++){

      // sets the Destination in X direction:
      do{
         // fist for the upper half of the square
         if(i <= iWorldSize){
            Dest.x =( ((iScreenWidth/2-iObjectSize/2*j)+(iObjectSize*h) ));
            h++;
         }
         // second for the lower half of the square
         else{
            Dest.x =( ((iScreenWidth/2-iObjectSize/2*j)+(iObjectSize*h) ));
            h++;
         }

         // decide whats to be drawn on Screen
         switch (vecWorldVector.get_vecWorldVectorTile(i)) {

            // draw nothing (other building will be drawn later)
            case 0:
                     break;
            // draw background
            case 1:  SDL_RenderCopy(_ptrRenderer, background, &Src, &Dest);
                     break;
         }
      } while(h <= j-1);      // the limit of elements in a row

      // prepare Variables for next run

      h = 0;   // reset to start at fist point of rows in X dir
      if(i <= iWorldSize){
         j++;     // reset how often h must be added (number of elements in row)
      }
      if(i > iWorldSize){
         j--;     // lower half of square elements are decreasing
      }
      Dest.y += (iObjectSize/2);  // next "line" on Screen
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
