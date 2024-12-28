#include "subsystems/Drive.hpp"
#include <frc2/command/CommandPtr.h>

Drive::Drive() : m_left(0), m_right(1)
{
    m_drive = std::make_shared<frc::DifferentialDrive>(m_left, m_right);
}
void Drive::DriveTank(double left, double right)
{
    m_drive->TankDrive(left, right);
}
void Drive::DriveArcade(double forward, double rot)
{
    m_drive->ArcadeDrive(forward, rot);
}
void Drive::Periodic()
{
}
frc2::CommandPtr&& Drive::GetDefaultCommand(DoubleSupplier forwardSupplier, DoubleSupplier rotationSupplier)
{
    return this->Run([=]()
    {
        this->DriveArcade(forwardSupplier(), rotationSupplier());
    });
}