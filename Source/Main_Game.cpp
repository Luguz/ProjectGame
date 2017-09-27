//
//    Game Project -> Space Strategy
//
//    Main_Game.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Main_Game.h"

/************ Constructor *****************************************************/

/*                             Standard-Constructor                           */

Main_Game::Main_Game(): _clGameState(clGameState::PLAY){  // Gamestate = PLAY
/*                           Graphic-Parameter                                */

   // Resolution Settings
   iSelectedScreenWidth =  1000;       // Screen width
   iSelectedScreenHeigth = 1000;       // Screen height
   iTileSize = 50;
   // Camera variables: Edge State (on start 0), mouse in middle of screen
   iCameraEdgeState = 0;               // no scrolling on start
   iCameraZoom = 0;                    // standard zoom faktor adjusted
   iMousePosX = iSelectedScreenWidth;  // set x on start (just to init.)
   iMousePosY = iSelectedScreenHeigth; // set y on start (just to init.)
   iEdgeSize  = 15;                    // area from screen edges in which you scroll

   // Field selection
   iSelectPosX = 0;
   iSelectPosY = 0;
/*                            Game-variables                                  */
   // Size of the World Home Base
   iPlayerWorldSize = 5;              // must be unequal


/*                           Basic-Game-functionalities                       */
   // allow SDL functions (Graphics) via BaseSDL in Main_Game
   BaseSDL = Screen_Graphics(iSelectedScreenWidth, iSelectedScreenHeigth, iPlayerWorldSize, iTileSize);
   // allow SDL functions (Audio) via AudioSDL in Main_Game
   AudioSDL = Audio_Playback();

   // creates world surface for starting World
   PlayerHomeBase = World_Vectors(iPlayerWorldSize);

}

/************ Starts the main Game functions **********************************/

// basic public start function -> used in main.cpp

void Main_Game::RunGame(){
   // initialize the basic game-functions
   _InitSystems();
   // starts game loop
   _GameLoop();
}

/************ Loop of the whole Game ******************************************/

// this loop is used by other functions to close the game
// let the important functions work as long game runs

void Main_Game::_GameLoop(){
   // functions that checks the Gamestate -> Loop
   while(_clGameState != clGameState::EXIT){
      // input check
      _InputCheck();
      // draw the game
      _DrawGame();
   }
   // Quit Game if Loop ends
   Mix_Quit();
   SDL_Quit();
}

/************ initialize Basic Game Systems ***********************************/

// initialize every important function/variable to run game

void Main_Game::_InitSystems(){

   // creates the Window
   BaseSDL.StartSDL(iSelectedScreenWidth,iSelectedScreenHeigth);

   // starts Audio functions
   AudioSDL.StartAudio();

}

/************ input Check of Player *******************************************/

// checks the input from player

void Main_Game::_InputCheck(){
SDL_Event evnt;      // variable for events ( 1 = pending; 2 = none available)

   // process inputs
   while (SDL_PollEvent(&evnt)) // while event true (=1)
   {
       switch (evnt.type) {
         // Quit game with close window button
         case SDL_QUIT:
            printf("Quit Button pressed\n");
            _clGameState = clGameState::EXIT;
            break;

         // take mousemotion (for now for the camera scrolling)
         // for information depending iCameraEdgeState see documentation
         /* case SDL_MOUSEMOTION:
            int x,y;
            SDL_GetMouseState(&x,&y);
            iMousePosX = x;
            iMousePosY = y;


            // mouse is on no screen edge (reset of iCameraEdgeState):
            if (iMousePosX > 0 && iMousePosX < iSelectedScreenWidth && iMousePosY > 0 && iMousePosY < iSelectedScreenHeigth){
               iCameraEdgeState = 0;
            }

            // all 8 edge/edgecorner combinations: (edge size set bit higher)

            // top left
            if(iMousePosY <= iEdgeSize && iMousePosX <= iEdgeSize) { iCameraEdgeState = 1;}
            // top
            if(iMousePosY == 0 && iMousePosX > iEdgeSize && iMousePosX < iSelectedScreenWidth-iEdgeSize ){ iCameraEdgeState = 2;}
            //top right
            if(iMousePosY <= iEdgeSize && iMousePosX >= iSelectedScreenWidth-iEdgeSize ){ iCameraEdgeState = 3;}

            // rigth
            if(iMousePosY > iEdgeSize && iMousePosY < iSelectedScreenHeigth-iEdgeSize && iMousePosX >= iSelectedScreenWidth-iEdgeSize ){ iCameraEdgeState = 4;}

            // bottom rigth
            if(iMousePosY >= iSelectedScreenHeigth-iEdgeSize && iMousePosX >= iSelectedScreenWidth-iEdgeSize ){ iCameraEdgeState = 5;}
            // bottom
            if(iMousePosY >= iSelectedScreenHeigth-iEdgeSize && iMousePosX < iSelectedScreenWidth-iEdgeSize && iMousePosX > iEdgeSize){ iCameraEdgeState = 6;}
            // bottom left
            if(iMousePosY >= iSelectedScreenHeigth-iEdgeSize && iMousePosX <= iEdgeSize){ iCameraEdgeState = 7;}

            // left
            if(iMousePosY < iSelectedScreenHeigth-iEdgeSize && iMousePosY > iEdgeSize && iMousePosX <= iEdgeSize){ iCameraEdgeState = 8;}

            //printf("x:%i y:%i\n",x,y );
         // end of SDL_MOUSEMOTION
            break;


         // zoom with camera
         case SDL_MouseWheel:
            // scroll up
            if(SDL_MouseWheel.y == 1){
               iCameraZoom += 1;
            }
            // scroll down
            if(SDL_MouseWheel.y == -1){
               iCameraZoom -= 1;
            }
         // end of zoom with camera
            break;
*/
         case SDL_KEYDOWN:
            switch(evnt.key.keysym.sym){
               case SDLK_UP:
               printf("UP\n");
               if(iSelectPosY >= 0){
                  iSelectPosY -= iTileSize;
               }
               break;
            case SDLK_DOWN:
               printf("DOWN\n");
               if(iSelectPosY <= iSelectedScreenHeigth){
                  iSelectPosY += iTileSize;
               }
               break;
            case SDLK_LEFT:
               printf("LEFT\n");
               if(iSelectPosX >= 0){
                  iSelectPosX -= iTileSize;
               }
               break;
            case SDLK_RIGHT:
               printf("RIGHT\n");
               if(iSelectPosX <= iSelectedScreenWidth){
                  iSelectPosX += iTileSize;
               }
               break;
            case SDLK_ESCAPE:
               _clGameState = clGameState::EXIT;
               SDL_Quit();
            default:
               break;
            }
            break;
         default:
            break;
       }
   }
}

/************ Start the graphics of the Game **********************************/

// draws the final game with help of Graphics.cpp

void Main_Game::_DrawGame(){
   // starts all functions for creating the graphics
   BaseSDL.GraphicsControl(PlayerHomeBase, iPlayerWorldSize, iSelectedScreenHeigth
      ,iSelectedScreenWidth, iCameraEdgeState, iCameraZoom, iSelectPosX, iSelectPosY);
}
