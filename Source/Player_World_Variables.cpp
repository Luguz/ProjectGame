//
//    Game Project -> Space Strategy
//
//    Player_World_Variables.cpp
//    copyrights by Lukas Guz
//

#include "Player_World_Variables.h"

//constructor
Player_World_Variables::Player_World_Variables()//:
   //iWorldsize(1000),
   //vecWorldVector(nullptr)
   {
}

//destructor
Player_World_Variables::~Player_World_Variables(){

}

void Player_World_Variables::BasicWorldCreation(){

   // running index
   int i = 0;

   // fill the world
   while(i < iWorldsize){
   vecWorldVector.push_back(1);
   i++;
   }


   printf(" World-Vector created object in vector: %i\n"
            // -1 because it begins with 0
            ,vecWorldVector[iWorldsize-1] );
}
