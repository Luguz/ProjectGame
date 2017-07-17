//
//    Game Project -> Space Strategy
//
//    GameStructure.cpp
//    copyrights by Lukas Guz
//

#include "GameStructure.h"

// constructor
GameStructure::GameStructure():
   _worldVector(0),
   _worldsize(100000){

}

// starts the world creation of the empty world
void GameStructure::StartWorldCreation(){
   // create and manage changes on world surface
   _BasicWorldCreation();
}

// controls the major functions in this class
void GameStructure::_WorldControl(){

}

// creates the basic starting world
void _BasicWorldCreation(){
   // running index
   int i = 0;
   int b = 10000;
   // fill the world
   while(i < b){
   _worldVector[i] = "GROUND";
   i++;
   }
}
