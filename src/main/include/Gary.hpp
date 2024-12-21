#include "subsystems/Drive.hpp"

class GaryContainer
{
public:
    GaryContainer();
    void ConfigureBindings();
    frc2::CommandPtr&& GetAutonomousCommand();
private:
    Drive m_drive;
};