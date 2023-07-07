#include "Hardware.h"

Hardware::Hardware() {

    wheel_front_left.setBrake(vex::brakeType::brake);
    wheel_back_left.setBrake(vex::brakeType::brake);
    wheel_front_right.setBrake(vex::brakeType::brake);
    wheel_back_right.setBrake(vex::brakeType::brake);

    left_wheels.setStopping(vex::brakeType::brake);
    right_wheels.setStopping(vex::brakeType::brake);

    drivetrain.setStopping(vex::brakeType::brake);
    disk_flicker.setStopping(vex::brakeType::brake);
    flywheel.setStopping(vex::brakeType::coast);
}
