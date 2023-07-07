#pragma once
#include "vex.h"

class Hardware
{

public:
    Hardware();

    vex::brain brain;
    vex::controller controller = vex::controller(vex::primary);

    // Drivetrain
    vex::motor wheel_front_left = vex::motor(vex::PORT1, vex::ratio18_1, false);
    vex::motor wheel_front_right = vex::motor(vex::PORT9, vex::ratio18_1, true);
    vex::motor wheel_back_left = vex::motor(vex::PORT2, vex::ratio18_1, true);
    vex::motor wheel_back_right = vex::motor(vex::PORT10, vex::ratio18_1, false);

    vex::motor_group left_wheels = vex::motor_group(wheel_front_left, wheel_back_left);
    vex::motor_group right_wheels = vex::motor_group(wheel_front_right, wheel_back_right);

    vex::motor_group drivetrain = vex::motor_group(wheel_front_left, wheel_back_left, wheel_front_right, wheel_back_right);

    // Disk launcher (flywheel and flicker)
    vex::motor flywheel_top = vex::motor(vex::PORT4, vex::ratio6_1, false);
    vex::motor flywheel_bottom = vex::motor(vex::PORT5, vex::ratio6_1, true);
    vex::motor_group flywheel = vex::motor_group(flywheel_top, flywheel_bottom);

    vex::motor disk_flicker = vex::motor(vex::PORT3, vex::ratio18_1, false);

    // Intake motors
    vex::motor intake_bottom = vex::motor(vex::PORT6, vex::ratio6_1, false);
    vex::motor intake_middle_left = vex::motor(vex::PORT7, vex::ratio6_1, true);
    vex::motor intake_middleR_right = vex::motor(vex::PORT8, vex::ratio6_1, false);
    vex::motor intake_top = vex::motor(vex::PORT20, vex::ratio6_1, true);

    vex::motor_group intake = vex::motor_group(intake_bottom, intake_middle_left, intake_middleR_right, intake_top); // Use this
};