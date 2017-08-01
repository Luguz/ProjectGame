//
//    Game Project -> Space Strategy
//
//    File_Manager.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__File_Manager__
#define  __GameProject__File_Manager__

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

class File_Manager{
public:
   //constructor
   File_Manager();

   // function and variables to read files to load Resources
   void LinkResources(std::string strFileType, std::string strNameObject);
   std::string strFilePath;

};

#endif //end of define(__GameProject__File_Manager__)
