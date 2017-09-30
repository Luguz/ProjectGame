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

   // Size of the World Home Base
   iPlayerWorldSize = 33;              // must be unequal
   iTileSize = 50;

   // timer varaibels
   StartTime = clock();

   // Resolution Settings
   iSelectedScreenWidth = 1700; //iTileSize*iPlayerWorldSize+iTileSize/2;       // Screen width
   iSelectedScreenHeigth = 1000; //iTileSize*((iPlayerWorldSize+1)/2);       // Screen height
   //printf("w:%i h:%i\n", iSelectedScreenWidth, iSelectedScreenHeigth);

   // Camera variables: Edge State (on start 0), mouse in middle of screen
   iCameraEdgeState = 0;               // no scrolling on start
   iCameraZoom = 0;                    // standard zoom faktor adjusted
   iMousePosX = iSelectedScreenWidth;  // set x on start (just to init.)
   iMousePosY = iSelectedScreenHeigth; // set y on start (just to init.)
   iEdgeSize  = 15;                    // area from screen edges in which you scroll

   // player position in World_Vectors
   iPlayerPos = 0;

   // creates world surface for starting World
   PlayerHomeBase = World_Vectors(iPlayerWorldSize);

/*                            Game-variables                                  */
  // Buildings
  LivingQuarters  = Buildings(102, 100, 1, 10, 0, 25);
  Factory         = Buildings(101, 200, 1, 10, 10);
  Street          = Buildings(100, 20, 1, 1);

  // Player
  //iCountFactory = 0;    //number of owned factories
  //iCountLivQuart = 0;   //number of owned livingguarters

  iBalance = 1000;     // your money
  iTitanium = 100;    // your Titanium
  iPopulation = 100;  // Population

  iProfit = 0;      // gettin money ohhh oh .... hopefully



/*                           Basic-Game-functionalities                       */
   // allow SDL functions (Graphics) via BaseSDL in Main_Game
   BaseSDL = Screen_Graphics(iSelectedScreenWidth, iSelectedScreenHeigth, iPlayerWorldSize, iTileSize);
   // allow SDL functions (Audio) via AudioSDL in Main_Game
   AudioSDL = Audio_Playback();





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

     //printf("StartTime%i clock: %i\n", StartTime, (unsigned long) clock() );
     PassedTime = ((unsigned long) clock() - StartTime ) / CLOCKS_PER_SEC;   // don't play at midnight or bad things may happen
      if(PassedTime >= 2){
        set_NewBalance();
       if(iBalance <= 0){
         _clGameState = clGameState::EXIT;
       }
       PassedTime = 0;
       StartTime = clock();
     }

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

         case SDL_KEYDOWN:
            switch(evnt.key.keysym.sym){

              // Movement
              case SDLK_UP:
                 //printf("UP to %i, Row:%i\n",iPlayerPos,(iPlayerPos/iPlayerWorldSize));
                 if(iPlayerPos > 0){
                    if((iPlayerPos/iPlayerWorldSize) % 2 == 0){
                      iPlayerPos  -= iPlayerWorldSize;
                    }else{
                      iPlayerPos  -= iPlayerWorldSize-1;
                    }
                 }else{
                   iPlayerPos = 0;
                 }
                 break;
              case SDLK_DOWN:
                 //printf("DOWN to %i, Row:%i\n",iPlayerPos,(iPlayerPos/iPlayerWorldSize));
                 if(iPlayerPos < iPlayerWorldSize*iPlayerWorldSize-1){
                    if((iPlayerPos/iPlayerWorldSize) % 2 == 0){
                      iPlayerPos  += iPlayerWorldSize-1;
                    }else{
                      iPlayerPos  += iPlayerWorldSize;
                    }
                  }else{
                    iPlayerPos = iPlayerWorldSize*iPlayerWorldSize-1;
                  }
                 break;
              case SDLK_LEFT:
                 //printf("LEFT to %i, Row:%i\n",iPlayerPos,(iPlayerPos/iPlayerWorldSize));
                 if(iPlayerPos > 0){
                    iPlayerPos--;
                 }else{
                   iPlayerPos = 0;
                 }
                 break;
              case SDLK_RIGHT:
                 //printf("RIGHT to %i, Row:%i\n",iPlayerPos,(iPlayerPos/iPlayerWorldSize));
                 if(iPlayerPos < iPlayerWorldSize*iPlayerWorldSize-1){
                    iPlayerPos++;
                  }else{
                    iPlayerPos = iPlayerWorldSize*iPlayerWorldSize-1;
                  }
                 break;

              //        Reset_Check_Variables(); Building
              case SDLK_0:
                 printf("Abriss\n");
                 if(PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos) > 0
                    && (get_iBalance() - 50 >= 0 )){
                   PlayerHomeBase.set_vecWorldVectorTile(iPlayerPos, 1);
                   iBalance -= 50;
                  }else{
                    printf("nix zum abreissen: %i\n",PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos));
                  }
                 break;
              case SDLK_1:      // Street
                 printf("Street build\n");
                 if(PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos) == 1
                    && (get_iBalance() - Street.get_BuildCost()) >= 0 ){
                   PlayerHomeBase.set_vecWorldVectorTile(iPlayerPos, 100);
                   set_BuildBalance(Street);
                  }else{
                    printf("ist bereits bebaut: %i ,oder du hast nicht genug Geld!\n",PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos));
                  }
                  break;
              case SDLK_2:        // factory
                  printf("Factory\n");
                  if(PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos) == 1
                    && (get_iBalance() - Factory.get_BuildCost()) >= 0 ){
                    PlayerHomeBase.set_vecWorldVectorTile(iPlayerPos, 101);
                    set_BuildBalance(Factory);
                  }else{
                    printf("ist bereits bebaut: %i ,oder du hast nicht genug Geld!\n",PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos));
                  }
                 break;
              case SDLK_3:        // LivingQuarters
                  printf("Living Quarters build\n");
                  if(PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos) == 1
                    && (get_iBalance() - LivingQuarters.get_BuildCost()) >= 0 ){
                    PlayerHomeBase.set_vecWorldVectorTile(iPlayerPos, 102);
                    set_BuildBalance(LivingQuarters);
                  }else{
                    printf("ist bereits bebaut: %i ,oder du hast nicht genug Geld!\n",PlayerHomeBase.get_vecWorldVectorTile(iPlayerPos));
                  }
                  break;





                 // End Game
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
      ,iSelectedScreenWidth, iCameraEdgeState, iCameraZoom, iPlayerPos, iBalance);
}


/************ Player Variables Calculations ***********************************/


void Main_Game::set_BuildBalance(Buildings Construction){
  iBalance -= Construction.get_BuildCost();
}

int Main_Game::set_NewBalance(){
  // reset
  iCountFactory = 0;
  iCountLivQuart = 0;

  int iTile = 0;
  while(iTile <= iPlayerWorldSize*iPlayerWorldSize-1){
      switch(PlayerHomeBase.get_vecWorldVectorTile(iTile)){
        case 101: iCountFactory++; break;             // count factories
        case 102: iCountLivQuart++; break;            // count living Quarters
      }
      iTile++;
  }
  // calculate your new balance
  iProfit = 0;
  iProfit += iCountFactory*Factory.get_Income() -
              iCountLivQuart*LivingQuarters.get_BuildMaintainCost();
  iBalance += iProfit;
  return iBalance;
}

int Main_Game::get_iBalance(){
  return iBalance;
}
