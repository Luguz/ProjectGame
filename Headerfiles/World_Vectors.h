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
/************ Structure to contain world informations *************************/

   // world vector including all information about the created word surface
   std::vector<int> vecWorldVector;


/************* PUPLIC *********************************************************/
public:

/************ Constructors ****************************************************/

   // standard constructor
   World_Vectors();

/*                       consturctors for worlds                              */

   // world vector with base functionalities
   World_Vectors(int iWorldsize);


/************ Destructor ******************************************************/

   // standard destructor
   ~World_Vectors();

/************ World_Vectors functions *****************************************/

   //function to get info of spezific place in World_Vectors
   int  get_vecWorldVector(int iPosOnWorld);

};


#endif //end of define(__GameProject__World_Vectors__)
