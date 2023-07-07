///////////////////////////////////////////////////////////////////////////////////
//                                                                            
//    Module:       main.cpp
//    Created:      2023-07-06
//    Description:  This demo code lets you control the VEX U Spinup Bot "Granny".
//                                                                           
///////////////////////////////////////////////////////////////////////////////////

#include "vex.h"
#include "Hardware.h"
#include "UserDrive.h"

using namespace vex;

void user_control(void) {
  Hardware* hw = new Hardware();
  UserDrive* us = new UserDrive(hw);

  while (true) {
    us->drive();
    vex::wait(20, vex::msec);  // Sleep the task for a short amount of time to prevent wasted resources.
  }
}


int main() {
  user_control();

  // Prevent main from exiting with an infinite loop.
  while (true) wait(100, msec);
  
}
