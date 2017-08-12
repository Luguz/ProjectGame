//
//    Game Project -> Space Strategy
//
//    Player_World_Variables.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__Player_World_Variables__
#define  __GameProject__Player_World_Variables__

#include <string>
#include <vector>

class Player_World_Variables{
public:

   //constructor
   Player_World_Variables();
   //destructor
   ~Player_World_Variables();


   // function to create starting world
   static const std::vector<int> vecWorldVector;       // vector with surface types

   // basic Variables selected by the player to create game
   static const int iWorldsize;                    // World size
   int iWorldsizeSquare;              // actual world size iWorldsizexiWorldsize
   std::string strBiomeType;                    // string with Biome type
   //function to create basic surface
   void BasicWorldCreation();

private:

};


#endif //end of define(__GameProject__Player_World_Variables__)
