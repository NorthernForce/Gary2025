#include "subsystems/Shooter.hpp"
#include <frc2/command/CommandPtr.h>

Shooter::Shooter() : shooter(4), indexer(5), beambreak(0)
{
}

void Shooter::Intake()
{
    indexer.Set(1.0);
}
void Shooter::FeedShooter()
{
    indexer.Set(1.0);
}
void Shooter::RampShooter()
{
    shooter.Set(1.0);
}
void Shooter::StopIntake()
{
    shooter.Set(0.0);
}
void Shooter::StopShooter()
{
    shooter.Set(0.0);
}
bool Shooter::HasPiece()
{
    return !beambreak.Get();
}
frc2::CommandPtr&& Shooter::GetIntakeCommand()
{
    return this->Run([&]()
    {
        this->Intake();
    }).Until([&]() {
        return this->HasPiece();
    }).AndThen([&]() {
        this->StopIntake();
    });
}
frc2::CommandPtr&& Shooter::GetShootCommand()
{
    return this->Run([&]()
    {
        this->RampShooter();
        this->FeedShooter();
    }).Until([&]() {
        return !this->HasPiece();
    }).AndThen([&]() {
        this->StopIntake();
        this->StopShooter();
    });
}
frc2::CommandPtr&& Shooter::GetDefaultCommand()
{
    return this->Run([&]()
    {
        this->StopShooter();
        this->StopIntake();
    });
}