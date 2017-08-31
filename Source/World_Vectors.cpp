//
//    Game Project -> Space Strategy
//
//    World_Vectors.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "World_Vectors.h"

// List of Biome Types
#define StandardMoon 1;

// Standard constructor
World_Vectors::World_Vectors(){

}

/******************This is spezific for the Player World ***************************************/

// constructor
World_Vectors::World_Vectors( int iWorldsize, int iWorldBiome){
   // debug features for iWorldsize
      if(iWorldsize > 10000000){ iWorldsize = 10000000;};  // max Worldsize
      if(iWorldsize < 100){ iWorldsize = 100; };           // min  Worldsize

   // creating of the Worldvector
      int k = 0;
      do{
        vecWorldVector.push_back(1);
        //printf("%i\n",vecWorldVector[k]);
        k++;
      }while(k < (iWorldsize*iWorldsize));
}



// destructor
World_Vectors::~World_Vectors(){

}

void World_Vectors::create_vecWorldVector(std::string strNameOfWorld,int iWorldsize, int strWorldBiome){

      World_Vectors PlayerHomeBase(iWorldsize,1);

}

/***********************************************************************************************/

int World_Vectors::get_vecWorldVector(int iPosOnWorld){

  int a = vecWorldVector[5];
  //return vecWorldVector[5];
  return a;
}
