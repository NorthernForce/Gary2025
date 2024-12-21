#include "subsystems/Drive.hpp"

Drive::Drive() : m_left_front(0), m_right_front(1), m_left_back(2), m_right_back(3)
{
    m_drive = std::make_shared<frc::DifferentialDrive>(m_left_front, m_right_front);
    m_left_front.AddFollower(m_left_back);
    m_right_front.AddFollower(m_right_back);
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
    return this->Run([this, forwardSupplier, rotationSupplier]()
    {
        this->DriveArcade(forwardSupplier(), rotationSupplier());
    });
}