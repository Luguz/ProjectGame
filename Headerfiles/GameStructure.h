//
//    Game Project -> Space Strategy
//
//    GameStructure.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__GameStructure__
#define  __GameProject__GameStructure__

#include <vector>

class GameStructure{
public:
   GameStructure();                      //constructor

   void StartWorldCreation();

private:
   // function and variable for basic surface
   int _worldsize                ;
   std::vector<char> _worldVector;      // vector with surface types
   void _BasicWorldCreation()    ;


   // manages the world surface
   void _WorldControl();




};

#endif //end of define(__GameProject__GameStructure__)
