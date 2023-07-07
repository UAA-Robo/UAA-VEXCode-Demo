#pragma once
#include "vex.h"

class Hardware
{

public:
    Hardware();

    vex::brain brain;
    vex::controller controller = vex::controller(vex::primary);

    // Drivetrain
    vex::motor wheelFrontLeft = vex::motor(vex::PORT1, vex::ratio18_1, false);
    vex::motor wheelFrontRight = vex::motor(vex::PORT9, vex::ratio18_1, true);
    vex::motor wheelBackLeft = vex::motor(vex::PORT2, vex::ratio18_1, true);
    vex::motor wheelBackRight = vex::motor(vex::PORT10, vex::ratio18_1, false);

    vex::motor_group leftWheels = vex::motor_group(wheelFrontLeft, wheelBackLeft);
    vex::motor_group rightWheels = vex::motor_group(wheelFrontRight, wheelBackRight);

    vex::motor_group drivetrain = vex::motor_group(wheelFrontLeft, wheelBackLeft, wheelFrontRight, wheelBackRight);

    // Disk launcher (flywheel and flicker)
    vex::motor flywheelTop = vex::motor(vex::PORT4, vex::ratio6_1, false);
    vex::motor flywheelBottom = vex::motor(vex::PORT5, vex::ratio6_1, true);
    vex::motor_group flywheel = vex::motor_group(flywheelTop, flywheelBottom);

    vex::motor diskFlicker = vex::motor(vex::PORT3, vex::ratio18_1, false);

    // Intake motors
    vex::motor intakeBottom = vex::motor(vex::PORT6, vex::ratio6_1, false);
    vex::motor intakeMiddleLeft = vex::motor(vex::PORT7, vex::ratio6_1, true);
    vex::motor intakeMiddleRight = vex::motor(vex::PORT8, vex::ratio6_1, false);
    vex::motor intakeTop = vex::motor(vex::PORT20, vex::ratio6_1, true);

    vex::motor_group intake = vex::motor_group(intakeBottom, intakeMiddleLeft, intakeMiddleRight, intakeTop); // Use this
};