// headerfile

//
//    Game Project -> Space Strategy
//
//    Screen_Camera.h
//    copyrights by Lukas Guz, Felix Korthals
//


#ifndef  __GameProject__Screen_Camera__
#define  __GameProject__Screen_Camera__

#include <SDL2/SDL.h>
#include <stdio.h>

class Screen_Camera{

   int iBottomBorder;   // defines border of bottom Screen (is not 0)
   int iRightBorder;    // defines border of rigth Screen (is not 0)

   int iVelocityX;      // defines the Velocity of the camera by X
   int iVelocityY;      // defines the Velocity of the camera by Y

   SDL_Rect camera;     // the actual camera (X,Y,Width,Height)

public:
   // Standard-Constructor
   Screen_Camera();

   // constructor (Camera defined by Size and Velocity)
   Screen_Camera(int iCameraSizeX , int iCameraSizeY, int iCameraVelocityX,
      int iCameraVelocityY, int iScreenWidth, int iScreenHeight);

   // get the postion of the camera
   int get_CameraPositionX();  // X
   int get_CameraPositionY();  // Y
   int get_CameraWidth();      // Width
   int get_CameraHeight();     // Height
   // camera movement
   void move_Camera(int);


};

#endif //end of define(__GameProject__Screen_Camera__)
