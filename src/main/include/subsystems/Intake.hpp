#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <units/velocity.h>
#include <units/temperature.h>
#include <units/voltage.h>
#include <units/current.h>
#include <frc/motorcontrol/PWMTalonSRX.h>
#include <frc/DigitalInput.h>


using DoubleSupplier = std::function<double()>;

class Intake : public frc2::SubsystemBase
{
public:
    Intake();
    void RunIntake();
    void MoveArm(double speed);
    void StopIntake();
    frc2::CommandPtr&& GetIntakeCommand(DoubleSupplier armSpeedSupplier);
    frc2::CommandPtr&& GetDefaultCommand(DoubleSupplier armSpeedSupplier);
private:
    frc::PWMTalonSRX intake, arm;
};