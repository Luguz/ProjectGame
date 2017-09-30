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

   int iVelocity;       // defines the Velocity of the camera

   SDL_Rect camera;     // the actual camera (X,Y,Width,Height)

   signed int iCameraZoomFactor; // Zoom faktor (default "No-Zoom" = 1)

public:
   // Standard-Constructor
   Screen_Camera();

   // constructor (Camera defined by Screen_size and World_Parameter)
   Screen_Camera(int , int , int , int );

   // get the postion of the camera
   int get_CameraVelocity();   // Velocity
   int get_CameraPositionX();  // X
   int get_CameraPositionY();  // Y
   int get_CameraWidth();      // Width
   int get_CameraHeight();     // Height
   int get_CameraZoom();       // Zoom-Factor

   // camera movement
   void move_Camera(int, int);   // move camera


};

#endif //end of define(__GameProject__Screen_Camera__)
