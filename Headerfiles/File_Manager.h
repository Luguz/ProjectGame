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
#include <fstream>      // write and read to/from file
#include <time.h>       // get time


class File_Manager{
public:
   //constructor
   File_Manager();

   // function and variables to read files to load Resources
   static std::string strFilePath;
   void LinkResources(std::string strFileType, std::string strNameObject);

   // function and variable to create, collect and save Errorcode
   std::string strErrorCode;
   void WriteErrorLog(std::string strErrorCode);

};

#endif //end of define(__GameProject__File_Manager__)
