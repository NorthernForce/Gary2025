#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <units/velocity.h>
#include <units/temperature.h>
#include <units/voltage.h>
#include <units/current.h>
#include <frc/motorcontrol/PWMTalonSRX.h>


using DoubleSupplier = std::function<double()>;

class Drive : public frc2::SubsystemBase
{
public:
    Drive();
    void DriveTank(double left, double right);
    void DriveArcade(double forward, double rotational);
    void Periodic() override;
    frc2::CommandPtr&& GetDefaultCommand(DoubleSupplier forwardSupplier, DoubleSupplier rotationSupplier);
private:
    std::shared_ptr<frc::DifferentialDrive> m_drive;
    frc::PWMTalonSRX m_left, m_right;
};