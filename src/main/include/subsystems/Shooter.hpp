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

class Shooter : public frc2::SubsystemBase
{
public:
    Shooter();
    void Intake();
    void FeedShooter();
    void RampShooter();
    void StopIntake();
    void StopShooter();
    bool HasPiece();
    frc2::CommandPtr&& GetIntakeCommand();
    frc2::CommandPtr&& GetShootCommand();
    frc2::CommandPtr&& GetDefaultCommand();
private:
    frc::PWMTalonSRX shooter, indexer;
    frc::DigitalInput beambreak;
};