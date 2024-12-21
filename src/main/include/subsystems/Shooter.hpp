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
private:
    frc::PWMTalonSRX shooter, indexer;
    frc::DigitalInput beambreak;
};