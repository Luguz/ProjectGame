//
//    Game Project -> Space Strategy
//
//    Player_World_Interaction.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Player_World_Interaction__
#define  __GameProject__Player_World_Interaction__

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <iostream>

class Player_World_Interaction{
public:
   Player_World_Interaction();       //constructor

   void StartWorldCreation();

private:

   // function and variable for basic surface
   int _iWorldsize;
   std::vector<std::string> _vecWorldVector;// vector with surface types
   void _BasicWorldCreation();

   // manages the world surface
   void _WorldControl();




};

#endif //end of define(__GameProject__Player_World_Interaction__)
