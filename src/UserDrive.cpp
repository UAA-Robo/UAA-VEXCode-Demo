#include "UserDrive.h"

UserDrive::UserDrive(Hardware *hardware) : Drive(hardware)
{
}

int UserDrive::get_flywheel_speed()
{
    return flywheel_voltage;
}

void UserDrive::drive()
{
    drive_train_controls();
    intake_controls();
    flywheel_controls();
    flick_disk_controls();
}

void UserDrive::drive_train_controls()
{
    const int DEAD_ZONE = 2;

    double forward_backward = (double)hw->controller.Axis3.position(vex::percentUnits::pct);
    double turning = (double)hw->controller.Axis1.position(vex::percentUnits::pct);

    if (std::abs(forward_backward) < DEAD_ZONE)
    {
        forward_backward = 0;
    }

    if (std::abs(turning) < DEAD_ZONE)
    {
        turning = 0;
    }

    move_drive_train({forward_backward, turning});
}

void UserDrive::intake_controls()
{
    if (hw->controller.ButtonL1.pressing())
    {
        spin_intake(false, false);
    }
    else if (hw->controller.ButtonX.pressing())
    {
        spin_intake(false, true);
    }
    else
    {
        spin_intake(true, true);
    }
}

void UserDrive::flywheel_controls()
{

    if (hw->controller.ButtonB.pressing())
    {
        flywheel_voltage = 12;
        hw->controller.Screen.clearScreen();
        hw->controller.Screen.setCursor(3, 1);
        hw->controller.Screen.print("Flywheel Volt: %.1lf", flywheel_voltage);
        vex::wait(100, vex::msec);
    }

    if (hw->controller.ButtonR1.pressing())
    {

        spin_flywheel(flywheel_voltage);
        // Rumble controller if flywheel is up to speed every 2 seconds
        if ((hw->flywheel_bottom.velocity(vex::velocityUnits::pct) + hw->flywheel_top.velocity(vex::velocityUnits::pct)) / 2.0 >= flywheel_voltage / 12.0 * 100 && (hw->brain.timer(vex::msec) - init_rumble_time) >= 1000)
        {
            hw->controller.rumble(".  ");
            init_rumble_time = hw->brain.timer(vex::msec);
        }
    }
    else if (hw->controller.ButtonY.pressing())
    {
        spin_flywheel(-flywheel_voltage);
    }
    else
    {
        spin_flywheel(0);
    }
}

void UserDrive::flick_disk_controls()
{
    if (hw->controller.ButtonR2.pressing())
    {
        flick_disk();
    }
}
