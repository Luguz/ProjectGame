//
//    Game Project -> Space Strategy
//
//    Graphics.cpp
//    copyrights by Lukas Guz
//

#include "Graphics.h"


Graphics::Graphics():
   _screenWidth(500),
   _screenHeight(500),
   _window(NULL),
   _renderer(NULL),
   _surface(NULL){

}

void Graphics::BasicSDL(){
   // initialize everything
   SDL_Init(SDL_INIT_EVERYTHING);
   if (SDL_Init(SDL_INIT_VIDEO != 0)){
      printf("error initializing SDL: %s\n", SDL_GetError());
   }

   // create the window
   SDL_Window *_window = SDL_CreateWindow("GameProject", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
   if (!_window){
      printf("error creating window: %s\n", SDL_GetError());
      SDL_Quit();
   }

   // disables screensaver
   void SDL_DisableScreenSaver(void);

   // create renderer
   _renderer = SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED
      |SDL_RENDERER_PRESENTVSYNC);
   if(!_renderer){
      printf("error creating renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(_window);
      SDL_Quit();
   }
}


void Graphics::_GraphicsControl(){


   // update window
   SDL_UpdateWindowSurface(_window);

}


void Graphics::_LoadGraphicResources(std::string fileType, std::string nameObject){

   // prepares the Type to be a file path
   fileType = fileType.append(".txt");
   fileType = fileType.insert(0,"Resources/");

   // opends the needed file by FileType(prepared)
   std::ifstream file;        // variable file that can use the needed functions
   file.open(fileType);       // open the needed file

   // prints error code if file was not opened correctly
   if (!file){
      printf("Error in Reading: %s\n", fileType.c_str());
   }else{

      // reading file and put this in variable lines
      std::string lines;
      unsigned int curRow = 0;

      while(std::getline(file, lines)){
         //search for the requested Object
         if (lines.find(nameObject) != std::string::npos){
            std:size_t pos = lines.find('"');
            filePath = lines.substr(pos);
         }
         // next line:
         curRow++;
      }
   }
   file.close();

}
