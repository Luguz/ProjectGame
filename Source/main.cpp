//
//    Game Project -> Space Strategy
//
//    main.cpp
//
//    make under Linux and Mac (tested only on Mac) with "make -j"
//    there is a clean, install and distclean option (for more Info. -> Readme)
//    makefile was original made by Hilton Lipschitz (for more Info- -> Readme)
//
//    main.cpp :: copyrights by Lukas Guz, Felix Korthals

#include "Main_Game.h"

int main(int, char**) {

   // include Main_Game in main
   Main_Game MainGame;


   // load constructor
   MainGame = Main_Game();
   // start the Game
   MainGame.RunGame();


   return 0;

}
