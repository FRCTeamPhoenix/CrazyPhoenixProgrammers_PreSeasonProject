#pragma once

#include <frc/commands/Command.h>
#include <frc/Joystick.h>

class DriveJoystick : public frc::Command{
    public:
        DriveJoystick();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;

    private:
        frc::Joystick m_xboxController = frc::Joystick(0);
        
};