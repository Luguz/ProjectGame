//
//    Game Project -> Space Strategy
//
//    World_Vectors.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "World_Vectors.h"



/****************** Constructors **********************************************/

/*                             Standard-Constructor                           */

// Standard constructor
World_Vectors::World_Vectors(){

}

/*                      Constructor- Basic/Minimum World                      */

// constructor for basic world type
World_Vectors::World_Vectors(int iWorldsize){
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

/****************** Destructors ***********************************************/

// standard Destructor
World_Vectors::~World_Vectors(){

}


/****************** get specific World_Vectors info ***************************/

int World_Vectors::get_vecWorldVector(int iPosOnWorld){

  return vecWorldVector[iPosOnWorld];

}
