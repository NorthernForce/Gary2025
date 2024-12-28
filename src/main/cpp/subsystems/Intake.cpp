#include "subsystems/Intake.hpp"
#include <frc2/command/CommandPtr.h>

Intake::Intake() : intake(7), arm(9)
{
}

void Intake::RunIntake()
{
    intake.Set(1.0);
}
void Intake::StopIntake()
{
    intake.Set(0.0);
}
void Intake::MoveArm(double speed)
{
    arm.Set(speed);
}
frc2::CommandPtr&& Intake::GetIntakeCommand(DoubleSupplier armSpeedSupplier)
{
    return this->Run([=]()
    {
        this->RunIntake();
        this->MoveArm(armSpeedSupplier());
    });
}
frc2::CommandPtr&& Intake::GetDefaultCommand(DoubleSupplier armSpeedSupplier)
{
    return this->Run([=]()
    {
        this->MoveArm(armSpeedSupplier());
        this->StopIntake();
    });
}