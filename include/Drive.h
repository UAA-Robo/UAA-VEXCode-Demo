#pragma once
#include "vex.h"
#include "Hardware.h"

class Drive
{

public:
protected:
    Drive(Hardware *hardware);

    Hardware *hw;

    /// @brief       Moves the drivetrain based on the horizontal percentage and vertical percentage passed in. Calls calculateDriveTrainVel
    ///             to convert those percentages to actual velocities in RPM.
    /// @param velPercent   Pair of doubles {verticalVelocityPercent, horizontalVelocityPercent} from -100 to 100
    ///                     that represent the percentage that the drivetrain should move forward/backward and left/right.
    ///                     For example of verticalVelocityPercent = 50  and horizontalVelocityPercent = 0, the bot
    ///                     will move forward at 50% velocity. Likewise if verticalVelocityPercent = 0  and
    ///                     horizontalVelocityPercent = 50, the drivetrain will rotate to the right at 50% velocity.
    ///                     Any combination of non-zero verticalVelocityPercents and horizontalVelocityPercents
    ///                     will cause the drivetrain to move in a arc.
    void move_drive_train(std::pair<double, double> velPercent);

    /// @brief  Spins the intake indefinitely unless IS_STOP is passed as true.
    /// @param IS_STOP       If true, stops the intake.
    /// @param IS_INVERT     If true, runs the intake in reverse;
    void spin_intake(bool IS_STOP = false, bool IS_INVERT = false, int volts = 12);

    /// @brief  Sets the voltage and spins the flywheel until the function is called again with a different voltage (like 0).
    /// @param voltage      Double from -12,000 to 12,000. Negative voltage reversed the flywheel.
    void spin_flywheel(double voltage);

    /// @brief Flicks the disk by moving the launcher/flicker forward and backward once.
    void flick_disk();

    std::pair<double, double> calculate_drive_train_velocity(std::pair<double, double> velPercent);
};