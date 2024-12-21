#include "subsystems/Drive.hpp"
#include "subsystems/Shooter.hpp"

class GaryContainer
{
public:
    GaryContainer();
    void ConfigureBindings();
    frc2::CommandPtr&& GetAutonomousCommand();
private:
    Drive m_drive;
    Shooter m_shooter;
};