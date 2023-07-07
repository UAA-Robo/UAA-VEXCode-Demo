#include "Drive.h"

Drive::Drive(Hardware *hardware)
{
    hw = hardware;
}

void Drive::move_drive_train(std::pair<double, double> velPercent)
{
    std::pair<double, double> vel = calculate_drive_train_velocity(velPercent);
    hw->left_wheels.spin(vex::directionType::fwd, vel.first, vex::velocityUnits::pct);
    hw->right_wheels.spin(vex::directionType::fwd, vel.second, vex::velocityUnits::pct);
}

void Drive ::spin_intake(bool ISSTOP, bool ISINVERT, int volts)
{
    if (ISSTOP)
    {
        hw->intake.stop();
    }
    else
    {
        if (ISINVERT)
        {
            hw->intake.spin(vex::directionType::rev, volts, vex::voltageUnits::volt);
        }
        else
        {
            hw->intake.spin(vex::directionType::fwd, volts, vex::voltageUnits::volt);
        }
    }
}

void Drive ::spin_flywheel(double voltage)
{
    if (voltage < 0)
    {
        hw->flywheel.spin(vex::directionType::rev, -voltage, vex::voltageUnits::volt);
    }
    else
    {
        hw->flywheel.spin(vex::directionType::fwd, voltage, vex::voltageUnits::volt);
    }
}

void Drive ::flick_disk()
{
    hw->disk_flicker.spin(vex::forward, 7, vex::volt);
    wait(150, vex::msec);
    hw->disk_flicker.spin(vex::reverse, 8, vex::volt);
    wait(200, vex::msec);
    hw->disk_flicker.stop();
}

std::pair<double, double> Drive::calculate_drive_train_velocity(std::pair<double, double> velPercent) //{vertical_velocity_percent, horizontal_velocity_percent}
{
    double vertical_velocity_percent = velPercent.first / 100;
    double horizontal_velocity_percent = velPercent.second / 100;

    // Calculate raw left and right motor velocity
    double raw_left_velocity = vertical_velocity_percent + horizontal_velocity_percent;  // raw velocity of left wheels in drive train
    double raw_right_velocity = vertical_velocity_percent - horizontal_velocity_percent; // raw velocity of right wheels in drive train

    // Normalize the motor velocity
    double max_raw_velocity = std::max(std::abs(raw_left_velocity), std::abs(raw_right_velocity));
    double normalization_factor = max_raw_velocity > 1.0 ? max_raw_velocity : 1.0;

    double left_velocity_multiplier = raw_left_velocity / normalization_factor;
    double right_velocity_multiplier = raw_right_velocity / normalization_factor;

    double left_velocity = 100 * left_velocity_multiplier;
    double right_velocity = 100 * right_velocity_multiplier;

    return {left_velocity, right_velocity};
}