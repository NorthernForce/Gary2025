#include "Gary.hpp"

#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc/MathUtil.h>

GaryContainer::GaryContainer()
{
}

DoubleSupplier TuneJoystickInput(DoubleSupplier supplier)
{
    return [supplier]() {
        double deadband = frc::ApplyDeadband(supplier(), 0.1);
        return deadband * abs(deadband);
    };
}

void GaryContainer::ConfigureBindings()
{
    frc2::CommandXboxController driverController{0};
    m_drive.SetDefaultCommand(m_drive.GetDefaultCommand(
        TuneJoystickInput([&driverController]() { return -driverController.GetLeftY(); }),
        TuneJoystickInput([&driverController]() { return -driverController.GetRightX(); })));
}

frc2::CommandPtr&& GaryContainer::GetAutonomousCommand()
{
    return frc2::CommandPtr(frc2::InstantCommand());
}