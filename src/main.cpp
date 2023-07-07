/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       wwami                                                     */
/*    Created:      4/18/2023, 12:20:06 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "Hardware.h"
#include"UserDrive.h"

using namespace vex;

void usercontrol(void) {
  Hardware* hw = new Hardware();
  UserDrive* us = new UserDrive(hw);
  while (true) {
    us->drive();
    vex::wait(20, vex::msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  usercontrol();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
