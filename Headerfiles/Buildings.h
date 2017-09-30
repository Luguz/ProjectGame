//
//    Game Project -> Space Strategy
//
//    Buildings.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__Buildings__
#define  __GameProject__Buildings__


class Buildings{

// building relevant variables
int iIndex;          // type of building
int iCost;           // cost of building
int iSize;           // size of building
int iMaintainCost;   // cost for maintaining building
int iTitaniumReq;    // titanium requirements to build
int iPopulation;     // population created
int iIncome;         // income of property


public:
   //constructor
 Buildings();
   // streets
   Buildings(int, int, int, int);
   // factory building
   Buildings(int, int, int, int, int);
   // living quarters building
   Buildings(int, int, int, int, int, int);

   int get_BuildCost();
   int get_BuildMaintainCost();
   int get_BuildIndex();
   int get_BuildSize();
   int get_ResTitaniumReq();
   int get_Income();



};

#endif //end of define(__GameProject__Buildings__)
