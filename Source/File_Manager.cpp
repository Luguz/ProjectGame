//
//    Game Project -> Space Strategy
//
//    FileManager.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "File_Manager.h"

//constructor
File_Manager::File_Manager():
   //strFilePath(""),
   strErrorCode(""){
}

// LoadResources
void File_Manager::LinkResources(std::string strFileType, std::string strNameObject){

   // prepares the Type to be a file path
   strFileType = strFileType.append(".txt");
   strFileType = strFileType.insert(0,"Resources/");

   // opends the needed file by FileType(prepared)
   std::ifstream file;        // variable file that can use the needed functions
   file.open(strFileType);       // open the needed file

   // prints error code if file was not opened correctly
   if (!file){
      printf("Error in Reading: %s\n", strFileType.c_str());
   }else{

      // reading file and put this in variable lines
      std::string lines;
      unsigned int curRow = 0;

      while(std::getline(file, lines)){
         //search for the requested Object
         if (lines.find(strNameObject) != std::string::npos){
            size_t pos = lines.find('"');
            strFilePath = lines.substr(pos);
         }
         // next line:
         curRow++;
      }
   }
   file.close();
}

// write to the ErrorLog.txt and print error to terminal
void File_Manager::WriteErrorLog(std::string strErrorCode){

   // get time Error took place
   time_t errorTime;                    // errorTime object with time_t functions
   struct tm *locTime;                  // struct containing Day/Time info in components
   // write time information in useable format
   errorTime = time(NULL);              // get the current time (in a raw format)
   locTime = localtime(&errorTime);     // make it to a local time (raw to readable)
   // put time info in whised format
   char cTimeOutput[30];                                       // char to safe time info
   strftime(cTimeOutput, 30, "|%Y|%d-%m|%H:%M:%S|", locTime);  // put time in format (string)

   // print the Error Code to the Terminal as well
   printf("%s: %s\n",cTimeOutput, strErrorCode.c_str());

   // make a temporary variable error with fstream functions
   std::fstream error;
   // open ErrorLog.txt with write options ("app" adds and does not delete previous txt)
   error.open("Resources/ErrorLog.txt", std::fstream::ate |std::fstream::app);
   // writing to the ErrorLog.txt (Time ErrorCode)
   error <<  cTimeOutput << ": " << strErrorCode << std::endl;

   error.close();
}
