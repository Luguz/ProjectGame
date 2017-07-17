//
//    Game Project -> Space Strategy
//
//    GameStructure.cpp
//    copyrights by Lukas Guz
//

#include "GameStructure.h"

// constructor
GameStructure::GameStructure():
   _worldsize(100000),
   _worldVector(0){

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
void GameStructure::_BasicWorldCreation(){
   // running index
   int i = 0;

   // fill the world
   while(i < _worldsize){
   _worldVector.push_back("GROUND");
   i++;
   }
}
