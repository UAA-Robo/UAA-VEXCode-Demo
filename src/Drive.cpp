#include "Drive.h"

Drive::Drive(Hardware* hardware) {
    hw = hardware;

}


void Drive::move_drive_train(std::pair<double,double> velPercent)
{
    std::pair<double,double> vel = calculate_drive_train_velocity(velPercent);
    hw->leftWheels.spin(vex::directionType::fwd, vel.first, vex::velocityUnits::pct);
    hw->rightWheels.spin(vex::directionType::fwd, vel.second, vex::velocityUnits::pct);
}


void Drive :: spin_intake(bool ISSTOP, bool ISINVERT, int volts) {
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


void Drive :: spin_flywheel(double voltage) {
    if(voltage < 0){
        hw->flywheel.spin(vex::directionType::rev, -voltage, vex::voltageUnits::volt);
    }else{
        hw->flywheel.spin(vex::directionType::fwd, voltage, vex::voltageUnits::volt);
    }
}


void Drive :: flick_disk() {
    hw->launcher.spin(vex::forward,7,vex::volt);
    wait(150,vex::msec);
    hw->launcher.spin(vex::reverse,8,vex::volt);
    wait(200,vex::msec);
    hw->launcher.stop();
}


std::pair<double,double> Drive::calculate_drive_train_velocity(std::pair<double,double> velPercent) //{verticalVelPercent, horizontalVelPercent}
{
        double verticalVelPercent = velPercent.first / 100;
        double horizontalVelPercent = velPercent.second / 100;

        // Calculate raw left and right motor velocity
        double rawLeftVel = verticalVelPercent + horizontalVelPercent; //raw velocity of left wheels in drive train
        double rawRightVel = verticalVelPercent - horizontalVelPercent; //raw velocity of right wheels in drive train
        
        // Normalize the motor velocity
        double maxRawVel = std::max(std::abs(rawLeftVel), std::abs(rawRightVel));
        double normalizationFactor = maxRawVel > 1.0 ? maxRawVel : 1.0;

        double leftVelMultiplier = rawLeftVel / normalizationFactor;
        double rightVelMultiplier = rawRightVel / normalizationFactor;


        double leftVel =  100 * leftVelMultiplier; 
        double rightVel =  100 * rightVelMultiplier;

        return {leftVel, rightVel};
}