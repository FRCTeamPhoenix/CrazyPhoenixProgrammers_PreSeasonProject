#include "commands/DriveJoystick.h"
#include "OI.h"

#include "subsystems/TankSubsystem.h"
#include "Robot.h"

DriveJoystick::DriveJoystick(){
    Requires(TankSubsystem::getInstance());
}

void DriveJoystick::Initialize(){
    TankSubsystem::getInstance()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Execute(){
    TankSubsystem::getInstance()->setSpeed(m_xboxController.GetRawAxis(XBOX_AXIS_LEFT_Y), m_xboxController.GetRawAxis(XBOX_AXIS_RIGHT_Y));
    if (m_xboxController.GetRawButton(XBOX_BUTTON_LEFT_BUMPER)) {
        TankSubsystem::getInstance()->setLowGear();
    }
    else if (m_xboxController.GetRawButton(XBOX_BUTTON_RIGHT_BUMPER)) {
        TankSubsystem::getInstance()->setHighGear();
    }
}

bool DriveJoystick::IsFinished(){
    return false;
}

void DriveJoystick::End(){
    TankSubsystem::getInstance()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Interrupted(){
    End();
}