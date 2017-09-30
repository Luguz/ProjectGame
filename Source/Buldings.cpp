//
//    Game Project -> Space Strategy
//
//    Buildings.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Buildings.h"

// Standart-Constructor
Buildings::Buildings(){

}

// street
Buildings::Buildings(int BuildIndex, int iBuildCost, int iBuildSize,
                      int iBuildMaintainCost){
  iIndex = BuildIndex;
  iCost = iBuildCost;
  iSize = iBuildSize;
  iMaintainCost = iBuildMaintainCost;
  iTitaniumReq = 0;
  iIncome = 0;
}

// factory
Buildings::Buildings(int iBuildIndex, int iBuildCost, int iBuildSize,
                      int iBuildMaintainCost, int ResTitaniumReq){
  iCost = iBuildCost;
  iIndex = iBuildIndex;
  iTitaniumReq = ResTitaniumReq;
  iIncome = 100;
  iMaintainCost = 0;
}


// living quarters
Buildings::Buildings(int iBuildIndex, int iBuildCost, int iBuildSize,
                      int iBuildMaintainCost, int ResTitaniumReq, int People){
  iCost = iBuildCost;
  iIndex = iBuildIndex;
  iTitaniumReq = ResTitaniumReq;
  iPopulation = People;
  iIncome = 0;
  iMaintainCost = iBuildMaintainCost;
}


// get variables functions
int Buildings::get_BuildCost(){ return iCost; }
int Buildings::get_BuildMaintainCost(){ return iMaintainCost; }
int Buildings::get_BuildIndex(){ return iIndex; }
int Buildings::get_BuildSize(){ return iSize; }
int Buildings::get_ResTitaniumReq(){ return iTitaniumReq; }
int Buildings::get_Income(){ return iIncome; }

// set variable functions
