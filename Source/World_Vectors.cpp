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
   if(iWorldSize < 0){ iWorldSize = 1; };               // min  Worldsize

   // number of Tiles/Fields in Worldvector out of Worldsize
   // remember that its isometric so the world must be a twisted square (45deg)



   // init vecWorldVector (fill with 0)
   int i = 0;
   do{
      vecWorldVector.push_back(0);
      i++;
   }while(i != iWorldSize*iWorldSize);


   int j = 1;               // row running index (starting in second line)
   int iLeftStart;          // left limiting element every row
   int iHalfWorldsize = (iWorldSize+1)/2;
   int a;                   // number of elements to the right left to fill

   // calculate the middle element of the first row
   int iMedian = ceil(iWorldSize/2);


   // upper half (triangle) of the world
   while(j < iHalfWorldsize){

      iLeftStart = iMedian-( floor(j/2) );      // calculate left limit for the playable area

      a = 0;
      while(a < j){                             // fill in ones from left to right
        vecWorldVector[iLeftStart+a] = 1;       // from 'iLeftStart' to (iLeftStart + j)
        a++;                                    // increment 'a' until it reaches 'j'
      }

      iMedian += iWorldSize;      // increment median (for next row)
      j++;                        // increment row running index
   }

   // bottom half (triangle) of the world
   while(j >= 1){

      iLeftStart = iMedian-( floor(j/2) );

      a = 0;
      while(a < j){
        vecWorldVector[iLeftStart+a] = 1;
        a++;
      }

      iMedian += iWorldSize;
      j--;
   }


   // DEBUG grafics
   int f = 0;
   do{
      if(f % iWorldSize == 0 && f != 0){
         printf("\n");
      };
      printf("%i ",vecWorldVector[f] );
      f++;
   }while(f <= iWorldSize*iWorldSize-1);
   printf("\n \n");

}


/****************** Destructors ***********************************************/

// standard Destructor
World_Vectors::~World_Vectors(){

}


/****************** get specific World_Vectors info ***************************/

// get the content of a spezific tile
int World_Vectors::get_vecWorldVectorTile(int iPosInWorld){
   //printf("vecWorldVector:%i\n",vecWorldVector[iPosInWorld]);
   return vecWorldVector[iPosInWorld];

}

// get the info about the size of the vector
int World_Vectors::get_vecWorldVectorSize(){
   return iNumberTiles;
}
