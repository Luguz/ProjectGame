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

   // function to create starting world
   std::vector<int> vecWorldVector;   // vector with surface types

   // basic Variables selected by the player to create game
   int iWorldsize;                             // World size
   std::string strBiomeType;                   // string with Biome type
   //function to create basic surface
   void BasicWorldCreation(std::string strBiomeType,int iWorldsize);

private:

};


#endif //end of define(__GameProject__Player_World_Variables__)
