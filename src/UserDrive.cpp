#include "UserDrive.h"

UserDrive::UserDrive(Hardware* hardware): Drive(hardware) 
{}

int UserDrive::getFlywheelSpeed()
{
    return flywheelVoltage;
}

void UserDrive::drive()
{
    //mirrorDriveToggle();
    driveTrainControls();
    intakeControls();
    flywheelControls();
    flickDiskControls();
    expandControls();
}

void UserDrive::driveTrainControls(){
    const int DEADZONE = 2;

    double forwardBackward = (double) hw->controller.Axis3.position(vex::percentUnits::pct);
    double turning = (double) hw->controller.Axis1.position(vex::percentUnits::pct);

    if(std::abs(forwardBackward) < DEADZONE){
        forwardBackward = 0;
    }


    if(std::abs(turning) < DEADZONE) {
        turning = 0;
    }

    moveDriveTrain({forwardBackward, turning});
}

void UserDrive::intakeControls(){
    if(hw->controller.ButtonL1.pressing()){
        spinIntake(false, false);
    }else if(hw->controller.ButtonX.pressing()){
        spinIntake(false, true);
    }else{
        spinIntake(true, true);
    }
}




void UserDrive::flywheelControls(){

    if(hw->controller.ButtonB.pressing()){
        flywheelVoltage = 12;
        hw->controller.Screen.clearScreen();
        hw->controller.Screen.setCursor(3,1);
        hw->controller.Screen.print("Flywheel Volt: %.1lf", flywheelVoltage);
        vex::wait(100, vex::msec);
    }

    //flywheelVoltage = 7.4;
    if(hw->controller.ButtonR1.pressing()){
        
        spinFlywheel(flywheelVoltage);
       //Rumble controller if flywheel is up to speed every 2 seconds
       if ((hw->flywheelBottom.velocity(vex::velocityUnits::pct)+hw->flywheelTop.velocity(vex::velocityUnits::pct))/2.0 >= flywheelVoltage/ 12.0 * 100
            && (hw->brain.timer(vex::msec) - initRumbleTime) >= 1000) 
        {
            hw->controller.rumble(".  ");
            initRumbleTime = hw->brain.timer(vex::msec);
        }
    }else if(hw->controller.ButtonY.pressing()){
        spinFlywheel(-flywheelVoltage);
    }else{
        spinFlywheel(0);
    }
}

void UserDrive::flickDiskControls(){
    if(hw->controller.ButtonR2.pressing()){
        flickDisk();
    }
}

void UserDrive::expandControls(){
    if(hw->controller.ButtonA.pressing()){
        expand();
    }
}

void UserDrive::mirrorDriveToggle(){
    mirrorDrive = (hw->controller.ButtonL2.pressing()) ? -1 : 1;
}