#include "subsystems/Shooter.hpp"
#include <frc2/command/CommandPtr.h>

Shooter::Shooter() : shooter(5)
{
}
void Shooter::RampShooter()
{
    shooter.Set(1.0);
}
void Shooter::StopShooter()
{
    shooter.Set(0.0);
}
frc2::CommandPtr&& Shooter::GetRampShooterCommand()
{
    return this->Run([=]()
    {
        this->RampShooter();
    });
}
frc2::CommandPtr&& Shooter::GetDefaultCommand()
{
    return this->Run([=]()
    {
        this->StopShooter();
    });
}