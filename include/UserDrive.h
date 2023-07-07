#include "Drive.h"

class UserDrive : public Drive
{
public:
    UserDrive(Hardware *hardware);
    int get_flywheel_speed();
    void drive();

private:
    // double flywheel_voltage = rc->lowFlywheelVoltUserDrive; //Sid
    double flywheel_voltage = 12; // Granny
    double init_rumble_time = 0;

    /// @brief  Controls drivetrain based on controller joysticks. Up/down on the left joystick is forward/backward.
    //          Left/right on the right joystick is turning.
    void drive_train_controls();

    /// @brief  Runs intake  while thee L1 controller bumper is held and reverse intake  while the X button is held.
    void intake_controls();

    /// @brief  Spins up flywheel while R1 controller bumper is held.
    void flywheel_controls();

    /// @brief  Flicks disk once when the R2 controller bumper is pressed. Flicks multiple times if held.
    void flick_disk_controls();
};