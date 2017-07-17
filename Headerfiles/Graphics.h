//
//    Game Project -> Space Strategy
//
//    Graphics.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Graphics__
#define  __GameProject__Graphics__

#include "MainGame.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

class Graphics{
public:
   // constructor
   Graphics();

   // starts basic SDL instances
   void BasicSDL();

   // manages graphic-functions(SDL)
   void _GraphicsControl();

private:
   // window related variables
   SDL_Window        *_window          ;
   SDL_Renderer      *_renderer        ;
   SDL_Surface       *_surface         ;
   int               _screenWidth      ;
   int               _screenHeight     ;

   // function and variables to read files to load Resources
   void _LoadGraphicResources(std::string fileType, std::string nameObject);
   std::string _filePath;

};




#endif //end of define(__GameProject__Graphics__)
