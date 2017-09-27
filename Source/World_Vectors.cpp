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



   float flMedian = ceil(iWorldSize/2);
   int iMedian = (int)flMedian;
   // init vecWorldVector (fill with 0)
   int i = 0;
   do{
      vecWorldVector.push_back(0);
      i++;
   }while(i != iWorldSize*iWorldSize);

   vecWorldVector[iMedian] = 1;

   int j = 2;                // row running index (starting in second line)
   //printf("J:%i\n",j );
   int a = 0;                // number of numbers left and right still to fill

   int iL = 1;          // left side of median running index
   int iR = 0;          // right side of median running index


   // upper half (triangle) of the world
   do{
      // median is not middle
      if (j % 2 == 0){
         iMedian += iWorldSize;                // new median (next row)
         //printf("iMedian:%i ;iR:%i\n",iMedian, iR );
         vecWorldVector[iMedian] = 1;          // fill place in new median

         a = 0;                             // reset running index
         do{
            a++;
            vecWorldVector[iMedian-a] = 1;     // fill left side from median
         }while(a != iL);                        // end when no places to fill

         a = 0;                                 // reset running index
         if(iR != 0){                           // when iR = 0 the loop would go to eternity
            do{
               //printf("a:%i iMew%i\n",a, iMedian);
               a++;
               vecWorldVector[iMedian+a] = 1;     // fill right side from median
            }while(a != iR );                      // end when no places to fill
         }
         // next line will have more numbers left and right:
         iL++;
         iR++;

      // else when median is in the middle
      }else{
         a = 0;
         iMedian += iWorldSize;         // fill median place
         vecWorldVector[iMedian] = 1;

         do{
            a++;
            // fill vecWorldVector left and right
            vecWorldVector[iMedian-a] = 1;
            vecWorldVector[iMedian+a] = 1;
         }while(a != (j-1)/2 );  // j is the row AND the number of numbers in the row but a = j/2 minus the middle element
      }

      j++;     // next row (and more numbers in the row)
      //printf("J:%i\n",j );
   }while(j != (iWorldSize+1)/2);         // ends when upper half plus next line is filled

   j--;
   printf("J:%i\n",j );
   //iL -= 1;
   //iR -= 1;
   // bottom half (triangle) of the world
   do{

      if (j % 2 == 0){
         iMedian += iWorldSize;
         vecWorldVector[iMedian] = 1;

         a = 0;
         do{
            a++;
            vecWorldVector[iMedian-a] = 1;
            //a++;
         }while(a != iL);
         a = 0;
         if(iR != 0){
            do{
               vecWorldVector[iMedian+a] = 1;
               a++;
            }while(a != iR );
         }
         // number of elements left and right decreases
         iL--;
         iR--;

      }else{
         a = 0;
         iMedian += iWorldSize;
         do{
            vecWorldVector[iMedian-a] = 1;
            vecWorldVector[iMedian+a] = 1;
            a++;
         }while(a != floor(j/2) );

      }

      j--;                    // bottom half the number of elements decrease
      //printf("J:%i\n",j );

   }while(j != 1);            // ends when no line remains

   //iMedian += iWorldSize;
   vecWorldVector[iMedian] = 1;

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
