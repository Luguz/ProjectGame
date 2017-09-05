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
World_Vectors::World_Vectors(int iWorldSize){
   // debug features for iWorldsize
   if(iWorldSize > 10000000){ iWorldSize = 10000000;};  // max Worldsize
   if(iWorldSize < 10){ iWorldSize = 10; };           // min  Worldsize

   // number of Tiles/Fields in Worldvector out of Worldsize
   // remember that its isometric so the world must be a twisted square (45deg)

   int i = 0;             // running index
   iNumberTiles = 0;  // holder of number of tiles calculated

   for(i=1;i <= iWorldSize; i++){ // function to calculate number of tiles (upper triangle)
      iNumberTiles += i;
      // double the triangle to get a square
      if(i == iWorldSize){
         iNumberTiles = ((iNumberTiles*2) -i); // -n to prevent double row in the middle
      }
   }

   // creating of the Worldvector
   i = 0;                 // reset the running index
   do{
     vecWorldVector.push_back(1);
     //printf("%i\n",vecWorldVector[k]);
     i++;
   }while(i < iNumberTiles);

}

/****************** Destructors ***********************************************/

// standard Destructor
World_Vectors::~World_Vectors(){

}


/****************** get specific World_Vectors info ***************************/

// get the content of a spezific tile
int World_Vectors::get_vecWorldVectorTile(int iPosOnWorld){

  return vecWorldVector[iPosOnWorld];

}

// get the info about the size of the vector
int World_Vectors::get_vecWorldVectorSize(){
   return iNumberTiles;
}
