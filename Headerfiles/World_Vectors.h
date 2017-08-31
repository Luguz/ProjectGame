//
//    Game Project -> Space Strategy
//
//    World_Vectors.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__World_Vectors__
#define  __GameProject__World_Vectors__

#include <string>
#include <vector>



class World_Vectors{
   // world vector including all information about the created word surface
   std::vector<int> vecWorldVector;     // vector with surface types

public:
   // standard constructor
   World_Vectors();
   /************Player World*********************************************/
   //constructor (creating worlds by size and biome)
   World_Vectors(int iWorldsize, int iWorldBiome);
   //destructor
   ~World_Vectors();
   /*********************************************************************/

   //function to create world surfaces
   void create_vecWorldVector(std::string strNameOfWorld ,int iWorldsize, int iWorldBiome);
   int  get_vecWorldVector(int iPosOnWorld);

};


#endif //end of define(__GameProject__World_Vectors__)
