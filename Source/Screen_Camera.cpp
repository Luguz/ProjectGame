//
//    Game Project -> Space Strategy
//
//    Screen_Camera.cpp
//    copyrights by Lukas Guz, Felix Korthals
//

#include "Screen_Camera.h"

// Standard-Constructor
Screen_Camera::Screen_Camera(){

}

// constructor
Screen_Camera::Screen_Camera(int iCameraSizeX, int iCameraSizeY,
   int iCameraVelocityX, int iCameraVelocityY, int iScreenWidth, int iScreenHeight){

   // set the camera on middle of screen (half of the Size obviously)
   camera.x = iScreenWidth/2;       // camera start position in x
   camera.y = iScreenHeight/2;      // camera start positon in y
   // set size of camera
   camera.w = iScreenWidth/2;       // size of camera width
   camera.h = iScreenHeight/2;      // size of camera height

   // get the World Size dimension and limit the camera movement
   iRightBorder  = iScreenWidth-camera.w;    // get the Screen Width
   iBottomBorder = iScreenHeight-camera.h;   // get the Screen Height

   iVelocityX = iCameraVelocityX;   // camera speed
   iVelocityY = iCameraVelocityY;   // camera speed

}

// function to move the camera
void Screen_Camera::move_Camera(int iCameraEdgeState){
   // fist check if camera should move or not (no mouse on edge/corner)
   printf("iCameraEdgeState:%i\n",iCameraEdgeState);
   if(iCameraEdgeState == 0){
      return;
   }

   // move camera and check if camera gets out of border (for simple screen borders)
   // top
   if (iCameraEdgeState == 2){
         camera.y -= iVelocityY;
   }
   // bottom
   if (iCameraEdgeState == 6){
         camera.y += iVelocityY;
   }
   // left
   if (iCameraEdgeState == 8){
         camera.x -= iVelocityX;
   }
   // right
   if (iCameraEdgeState == 4){
         camera.x += iVelocityX;
   }

   // move camera and check if camera gets out of border (for corner screen borders)
   // top/left
   if (iCameraEdgeState == 1){
         camera.x -= iVelocityX;
         camera.y -= iVelocityY;
   }
   // top/right
   if (iCameraEdgeState == 3){
         camera.x += iVelocityX;
         camera.y -= iVelocityY;
   }
   // bottom/left
   if (iCameraEdgeState == 7){
         camera.x -= iVelocityX;
         camera.y += iVelocityY;
   }
   //bottom/right
   if (iCameraEdgeState == 5){
         camera.x += iVelocityX;
         camera.y -= iVelocityY;
   }

   // limits for camera.x and camera.y
   if(camera.x >= iRightBorder) { camera.x = iRightBorder   ;}  // right border x
   if(camera.x <= 0)            { camera.x = 0              ;}  // left border x
   if(camera.y >= iBottomBorder){ camera.y = iBottomBorder  ;}  // bottom border y
   if(camera.y <= 0)            { camera.y = 0              ;}  // top border y

   // reset iCameraEdgeState (to be safe can changed by functions anytime
   //anyway and stop scrolling when minimizing game)
   iCameraEdgeState = 0;
}

// get the postion of the Camera and Width, Height
int Screen_Camera::get_CameraPositionX(){ return camera.x; }  // return x position
int Screen_Camera::get_CameraPositionY(){ return camera.y; }  // return y position
int Screen_Camera::get_CameraWidth()    { return camera.w; }  // return Width
int Screen_Camera::get_CameraHeight()   { return camera.h; }  // return Height
