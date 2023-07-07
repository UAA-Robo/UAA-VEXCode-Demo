#pragma once
#include "vex.h"

class Hardware{

public:
    //Constructors
    Hardware();

    void startupCheck();

    vex::brain brain;
    vex::controller controller = vex::controller(vex::primary);
    vex::motor wheelLeftFront = vex::motor(vex::PORT1, vex::ratio18_1, false);
    vex::motor wheelLeftBack = vex::motor(vex::PORT2, vex::ratio18_1, true);
    vex::motor wheelRightFront = vex::motor(vex::PORT9, vex::ratio18_1, true);
    vex::motor wheelRightBack = vex::motor(vex::PORT10, vex::ratio18_1, false);

    vex::motor_group leftWheels = vex::motor_group(wheelLeftFront, wheelLeftBack);
    vex::motor_group rightWheels = vex::motor_group(wheelRightFront, wheelRightBack);

    vex::motor_group driveTrain = vex::motor_group(wheelLeftFront, wheelLeftBack, wheelRightFront, wheelRightBack);

    vex::motor flywheelTop = vex::motor(vex::PORT4, vex::ratio6_1, false);
    vex::motor flywheelBottom = vex::motor(vex::PORT5, vex::ratio6_1, true);
    vex::motor_group flywheel = vex::motor_group(flywheelTop, flywheelBottom); //Use this

    vex::motor launcher = vex::motor(vex::PORT3, vex::ratio18_1, false);    //Use thi

    // intake motors
    vex::motor intakeBackLeft = vex::motor(vex::PORT6, vex::ratio6_1, false);
    vex::motor intakeMiddlLeft = vex::motor(vex::PORT7, vex::ratio6_1, true);
    vex::motor intakeMiddleRight = vex::motor(vex::PORT8, vex::ratio6_1, false);
    vex::motor intakeTopRight = vex::motor(vex::PORT20, vex::ratio6_1, true);

    vex::motor_group intake = vex::motor_group(intakeBackLeft, intakeMiddlLeft, intakeMiddleRight, intakeTopRight); //Use this
};