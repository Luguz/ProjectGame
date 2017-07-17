//
//    Game Project -> Space Strategy
//
//    RessourceLinker.h
//    copyrights by Lukas Guz
//


#ifndef  __GameProject__RessourceLinker__
#define  __GameProject__RessourceLinker__

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

class RessourceLinker{
public:
   //constructor
   RessourceLinker();

   // function and variables to read files to load Resources
   void LoadResources(std::string fileType, std::string nameObject);
   std::string _filePath;

};

#endif //end of define(__GameProject__RessourceLinker__)
