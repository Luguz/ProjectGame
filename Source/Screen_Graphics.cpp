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
   Dest.w = iSizeOfTile;		   //Destination set for width and height
   Dest.h = iSizeOfTile;

   // source variables for background
   SrcBack.x = 0;               //Source set for x and y
   SrcBack.y = 0;
   SrcBack.w = iScreenWidth;    //Soruce set for width and height
   SrcBack.h = iScreenHeight;

   // destination on screen variables  (init)
   DestBack.x = 0;		            //Destination set for x and y
   DestBack.y = 0;
   DestBack.w = iScreenWidth;	  	//Destination set for width and height
   DestBack.h = iScreenHeight;


   // text destination on screen variables  (init)
   Dest_Text.x = 10;		   //Destination set for x and y
   Dest_Text.y = 10;
   Dest_Text.w = 300;		   //Destination set for width and height
   Dest_Text.h = 50;

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
   SDL_Window *_ptrWindow = SDL_CreateWindow("GameProject", 0/*SDL_WINDOWPOS_CENTERED*/,
      0, iScreenWidth, iScreenHeight, SDL_WINDOW_SHOWN);
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

   // initialize ttf
   TTF_Init();
   //loading font
   font = TTF_OpenFont("Resources/Fonts/moonhouse.ttf", 128);
   font_color = {255, 255, 255};


   // Load Textures
   LoadTextures();





}

/****************** Control the functionalities of SDL (Graphics) *************/

// combines and manages all Graphic functions
void Screen_Graphics::GraphicsControl(World_Vectors vecWorldVector, int iWorldSize,
   int iScreenHeight, int iScreenWidth, int iCameraEdgeState, int iCameraZoom,
   int iPlayerPos, int iBalance){


   // move Camera depending on iCameraEdgeState (see documentation depending variable)
   //PlayerCamera.move_Camera(iCameraEdgeState, iCameraZoom);

   // draws the World Surface of the chosen Vector
   DrawWorldSurface(vecWorldVector, iPlayerPos, iBalance);

   // update window (a function by SDL)
   SDL_UpdateWindowSurface(_ptrWindow);

}

/****************** Draw the Graphics on Screen *******************************/

// Draws the surface out of Worldvector from Loaded Textures from LoadTextures
void Screen_Graphics::DrawWorldSurface(World_Vectors vecWorldVector, int iPlayerPos, int iBalance){

SDL_RenderCopy(_ptrRenderer, spacebackground, &SrcBack, &DestBack);

int x = 0;
// render text
//for(x = 0; x == 3; x++){
do{
  switch(x){
    case 0: strText << "Cash : ";
            strText << iBalance;
            Dest_Text.y += 10;
            break;
    case 1: strText << "[1] Strasse: Kosten = 20";
            break;
    case 2: strText << "[2] Fabrik: Kosten = 200";
            break;
    case 3: strText << "[3] Wohnung: Kosten = 100";
            break;
  }

_ptrSurface = TTF_RenderText_Solid(font, strText.str().c_str(), font_color);
balance_value = SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
SDL_FreeSurface(_ptrSurface);

SDL_RenderCopy(_ptrRenderer, balance_value, NULL, &Dest_Text);
SDL_DestroyTexture(balance_value);
Dest_Text.y += Dest_Text.h;
strText.str("");
x++;
}while(x <= 3);

Dest_Text.y = 10;


// render background
int iRowPlace = 1;
int iEven = 1;

do{

   do {
      // draw ground tile
      if (vecWorldVector.get_vecWorldVectorTile(iTile) >= 1){
      SDL_RenderCopy(_ptrRenderer, background, &Src, &Dest);
      }

      // decide whats to be drawn on Screen
      //printf("%i\n",iTile );
      switch (vecWorldVector.get_vecWorldVectorTile(iTile)) {
        // draw streets
        case 100: SDL_RenderCopy(_ptrRenderer, streets, &Src, &Dest);
                break;
        // draw factory
        case 101: SDL_RenderCopy(_ptrRenderer, factory, &Src, &Dest);
                break;
        // draw living quarters
        case 102: SDL_RenderCopy(_ptrRenderer, livingquarters, &Src, &Dest);
                break;
        default:
                break;
      }

      // draw pointer
      if(iTile == iPlayerPos){
        SDL_RenderCopy(_ptrRenderer, selectionField, &Src, &Dest);
      }

      // if number of row is even add an offset to x
      if(iEven % 2 == 0){
        Dest.x = iTileSize*iRowPlace+iTileSize/2;
      }else{
        Dest.x = iTileSize*iRowPlace;
      }

      iTile++;
      iRowPlace++;

   }while(iRowPlace % (iWorldSize+1) != 0);

   // reset Dest for x and y for next row
   Dest.y += iTileSize/2;
   //printf("iRow:%i Desty:%i",iRowPlace,Dest.y);
   Dest.x = 0;
   iRowPlace = 1;
   iEven++;

}while(iTile <= iWorldSize*iWorldSize-1);

// selection field render
//Dest.x = iSelectPosX;
//Dest.y = iSelectPosY;
//SDL_RenderCopy(_ptrRenderer, selectionField, &Src, &Dest);

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
   _ptrSurface = IMG_Load("Resources/Textures/PlanetGround.png");
   background	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   _ptrSurface = IMG_Load("Resources/Textures/Selection.png");
   selectionField	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   _ptrSurface = IMG_Load("Resources/Textures/Space.png");
   spacebackground	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   _ptrSurface = IMG_Load("Resources/Textures/Factory.png");
   factory	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   _ptrSurface = IMG_Load("Resources/Textures/Street.png");
   streets	= SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   _ptrSurface = IMG_Load("Resources/Textures/LivingQuarters.png");
   livingquarters = SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
   SDL_FreeSurface(_ptrSurface);

   // create fonts
   _ptrSurface = TTF_RenderText_Solid(font, "Balance: ", font_color);
   balance_text = SDL_CreateTextureFromSurface(_ptrRenderer, _ptrSurface);
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
