//
//    Game Project -> Space Strategy
//
//    ResourceLinker.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__ResourceLinker__
#define  __GameProject__ResourceLinker__

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

class ResourceLinker{
public:
   //constructor
   ResourceLinker();

   // function and variables to read files to load Resources
   void LoadResources(std::string fileType, std::string nameObject);
   std::string _filePath;

};

#endif //end of define(__GameProject__ResourceLinker__)
