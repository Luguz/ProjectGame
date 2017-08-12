//
//    Game Project -> Space Strategy
//
//    Player_World_Variables.cpp
//    copyrights by Lukas Guz
//

#include "Player_World_Variables.h"

//constructor
Player_World_Variables::Player_World_Variables():
   iWorldsize(10000)//,
   //vecWorldVector(nullptr)
   {
}

//destructor
Player_World_Variables::~Player_World_Variables(){

}

void Player_World_Variables::BasicWorldCreation(){

   // running index
   int i = 0;           // for world vector
   int j = 0;           // for world mask

   int iWorldsizeSquare = iWorldsize*iWorldsize;     // iworldsize in square

   // fill the world
   while(i < iWorldsizeSquare){
   vecWorldVector.push_back(1);
   i++;
   }

   // print some informations about the basic world creation:
   // print the last object in Worldvec to check the creation
   printf(" World-Vector created object in vector: %i\n"
            // -1 because it begins with 0
            ,vecWorldVector[iWorldsize-1]);
   // print the chosen world size
   printf(" chosen Worldsize (iWorldsize^2): %i\n", iWorldsizeSquare);
}
