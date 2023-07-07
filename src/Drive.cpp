#include "Drive.h"

Drive::Drive(Hardware* hardware) {
    hw = hardware;

}


void Drive::moveDriveTrain(std::pair<double,double> velPercent)
{
    std::pair<double,double> vel = calculateDriveTrainVel(velPercent);

    hw->leftWheels.spin(vex::directionType::fwd, vel.first, vex::velocityUnits::pct);
    hw->rightWheels.spin(vex::directionType::fwd, vel.second, vex::velocityUnits::pct);
}


void Drive :: spinIntake(bool ISSTOP, bool ISINVERT, int volts) {
    if (ISSTOP) {
        hw->intake.stop();
    }else {
        if(ISINVERT){
            hw->intake.spin(vex::directionType::rev, volts, vex::voltageUnits::volt);
        }else{
            hw->intake.spin(vex::directionType::fwd, volts, vex::voltageUnits::volt);
        }
    }
}

void Drive :: spinFlywheel(double voltage) {
    if(voltage < 0){
        hw->flywheel.spin(vex::directionType::rev, -voltage, vex::voltageUnits::volt);
    }else{
        hw->flywheel.spin(vex::directionType::fwd, voltage, vex::voltageUnits::volt);
    }
}


void Drive :: flickDisk() {

    hw->launcher.spin(vex::forward,7,vex::volt);
    wait(150,vex::msec);
    hw->launcher.spin(vex::reverse,8,vex::volt);
    wait(200,vex::msec);
    hw->launcher.stop();
}

