#pragma once

#include "subsystems/Drive.hpp"
#include "subsystems/Shooter.hpp"
#include "subsystems/Indexer.hpp"
#include "subsystems/Intake.hpp"

class GaryContainer
{
public:
    GaryContainer();
    void ConfigureBindings();
    frc2::CommandPtr&& GetAutonomousCommand();
private:
    Drive m_drive;
    Shooter m_shooter;
    Indexer m_indexer;
    Intake m_intake;
};