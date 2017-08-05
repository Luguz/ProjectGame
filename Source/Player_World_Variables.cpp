//
//    Game Project -> Space Strategy
//
//    Player_World_Variables.cpp
//    copyrights by Lukas Guz
//

#include "Player_World_Variables.h"

//constructor
Player_World_Variables::Player_World_Variables()//:
   //iWorldsize(0),
   //vecWorldVector(0)
   {
     iWorldsize = 0;
     vecWorldVector = 0;
}

void Player_World_Variables::BasicWorldCreation(std::string strBiomeType, int iWorldsize){

   // running index
   int i = 0;

   // fill the world
   while(i < iWorldsize+1){
   vecWorldVector.push_back(1);
   i++;
   }
   printf(" World-Vector created object in vector: %i\n"
            ,vecWorldVector[iWorldsize] );

}
