//
//    Game Project -> Space Strategy
//
//    Player_World_Interaction‚.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Player_World_Interaction.h"

// constructor
Player_World_Interaction::Player_World_Interaction():
   _iWorldsize(1000),
   _vecWorldVector(0){

}


// starts the world creation of the empty world
void Player_World_Interaction::StartWorldCreation(){
   // create and manage changes on world surface
   _BasicWorldCreation();
}

// controls the major functions in this class
void Player_World_Interaction::_WorldControl(){

}

// creates the basic starting world
void Player_World_Interaction::_BasicWorldCreation(){
   // running index
   int i = 0;

   // fill the world
   while(i < _iWorldsize+1){
   _vecWorldVector.push_back("GROUND");
   i++;
   }
   printf(" World-Vector created last object in vector: %s\n"
            ,_vecWorldVector[_iWorldsize].c_str() );
}
