//
//    Game Project -> Space Strategy
//
//    Screen_Graphics.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Graphics__
#define  __GameProject__Graphics__

#include <SDL2/SDL.h>         // basic SDL functions
#include <SDL2/SDL_image.h>   // for Loading Images
#include <stdio.h>
#include <string>

#include "World_Vectors.h"    // info about the WorldVector and Size
#include "Screen_Camera.h"    // info about what to render (what the player see)

class Screen_Graphics{

/************ Variables for the Window ****************************************/

   // window related variables
   SDL_Window        *_ptrWindow          ;    // save window information
   SDL_Renderer      *_ptrRenderer        ;    // save render information
   SDL_Surface       *_ptrSurface         ;    // save surface information

/************ Variables to draw Window ****************************************/

   // get the info about the player camera
   Screen_Camera PlayerCamera;
   int iCameraX ;                              // holds x postion of camera
   int iCameraY ;                              // holds y postion of camera
   int iCameraW ;                              // holds Width  of camera
   int iCameraH ;                              // holds Height of camera

   // destination of Image from Source
   SDL_Rect Src;		// Destination of Source of Image

   // Destination of the Image on Screen
   SDL_Rect Dest;		// Destination of Image on Screen


/************ Functions to manage Graphics ************************************/

   // Load Textures from Surface needed by DrawWorldSurface
   void LoadTextures();

   // draw the World on Screen out of vecWorldVector
   void DrawWorldSurface(World_Vectors, int, int, int, int);

   // list of Textures needed to be loaded in Game
   SDL_Texture    *background;





/************* PUPLIC *********************************************************/
public:

/************* Constructor ****************************************************/

   // Standard-Constructor
   Screen_Graphics();

   // constructor
   Screen_Graphics(int iScreenWidth, int iScreenHeight);

/************ Screen_Graphic functions ****************************************/

   // starts basic SDL instances
   void StartSDL(int, int);

   // manages graphic-functions(SDL) and changes
   void GraphicsControl(World_Vectors, int, int, int, int);

};





#endif //end of define(__GameProject__Graphics__)
