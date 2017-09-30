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
Screen_Camera::Screen_Camera(int iScreenWidth, int iScreenHeight, int iWorldSize, int iTileSize){

   // set the camera on middle of screen (half of the Size obviously)
   camera.x = 100;                  // camera start position in x
   camera.y = 100;                  // camera start positon in y
   // set size of camera
   camera.w = iScreenWidth;       // size of camera width
   camera.h = iScreenHeight;      // size of camera height

   // get the World Size dimension and limit the camera movement
   iRightBorder  = (iWorldSize*iTileSize)-camera.w;    // get the Screen Width
   iBottomBorder = (iWorldSize*iTileSize)-camera.h;   // get the Screen Height

   iVelocity = 2;   // camera speed

   iCameraZoomFactor = 0; // zoom factor

}

// function to move the camera
void Screen_Camera::move_Camera(int iCameraEdgeState, int iCameraZoom){
   // fist check if camera should move or not (no mouse on edge/corner)
   if(iCameraEdgeState != 0){
      printf("iCameraEdgeState:%i\n",iCameraEdgeState);

   }
   if(iCameraEdgeState == 0){
      return;
   }

   int iX = camera.x;
   int iY = camera.y;

printf("x:%i y:%i\n",iX, iY );
   // move camera and check if camera gets out of border (for simple screen borders)
   // top
   if (iCameraEdgeState == 2 /*&& iY > 0*/){
      printf("pup\n");
      camera.y -= iVelocity;
   }
   // bottom
   if (iCameraEdgeState == 6 /*&& iY < iBottomBorder*/){
      camera.y += iVelocity;
   }
   // left
   if (iCameraEdgeState == 8 /*&& iX > 0*/){
      camera.x -= iVelocity;
   }
   // right
   if (iCameraEdgeState == 4 /*&& iX < iRightBorder*/){
      camera.x += iVelocity;
   }

   // move camera and check if camera gets out of border (for corner screen borders)
   // top/left
   if (iCameraEdgeState == 1 /*&& iX > 0 && iY > 0*/){
      camera.x -= iVelocity;
      camera.y -= iVelocity;
   }
   // top/right
   if (iCameraEdgeState == 3 /*&& iY > -1 && iX < iRightBorder*/){
      camera.x += iVelocity;
      camera.y -= iVelocity;
   }
   // bottom/left
   if (iCameraEdgeState == 7 /*&& iX > 0 && iY < iBottomBorder*/){
      camera.x -= iVelocity;
      camera.y += iVelocity;
   }
   //bottom/right
   if (iCameraEdgeState == 5 /*&& iY > 0 && iX < iRightBorder*/){
      camera.x += iVelocity;
      camera.y += iVelocity;
   }

   printf("x:%i y:%i\n",camera.x, camera.y );

   // limits for camera.x and camera.y
   //if(camera.x > iRightBorder) { camera.x = iRightBorder   ;}  // right border x
   //if(camera.x < 0)            { camera.x = 0              ;}  // left border x
   //if(camera.y > iBottomBorder){ camera.y = iBottomBorder  ;}  // bottom border y
   //if(camera.y < 0)            { camera.y = 0              ;}  // top border y

   // reset iCameraEdgeState (to be safe can changed by functions anytime
   //anyway and stop scrolling when minimizing game)
   iCameraEdgeState = 0;

   // handeling Chosen Zoom faktor
   //if (iCameraZoom == -1){
      //iCameraZoomFactor = -10;                // zoom one time out
   //}
   if (iCameraZoom == 0){
      iCameraZoomFactor = 1;                 //standard zoom (no zoom)
   }
   if (iCameraZoom == 1){
      iCameraZoomFactor = 10;                // zoom one time in
   }

}

// get the postion of the Camera and Width, Height
int Screen_Camera::get_CameraPositionX(){ return camera.x; }  // return x position
int Screen_Camera::get_CameraPositionY(){ return camera.y; }  // return y position
int Screen_Camera::get_CameraWidth()    { return camera.w; }  // return Width
int Screen_Camera::get_CameraHeight()   { return camera.h; }  // return Height
int Screen_Camera::get_CameraVelocity() { return iVelocity;}  // returns the velocity of the camera
int Screen_Camera::get_CameraZoom()     { return iCameraZoomFactor;}// returns zoom faktor of camera
