#pragma once

#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include "RobotMap.h"

class PCMHandler {
    private:
        frc::Compressor compressor = frc::Compressor(1);
        frc::Solenoid highgearSol = frc::Solenoid(PCM_CAN_ID, SOLENOID_HIGH_GEAR);
        frc::Solenoid lowgearSol = frc::Solenoid(PCM_CAN_ID, SOLENOID_LOW_GEAR);
        frc::Solenoid clawSolRight = frc::Solenoid(PCM_CAN_ID, PCM_BALL_MANIPULATOR_RIGHT);
        frc::Solenoid clawSolLeft = frc::Solenoid(PCM_CAN_ID, PCM_BALL_MANIPULATOR_LEFT);

        frc::Solenoid clawSolRight2 = frc::Solenoid(PCM_CAN_ID, PCM_BALL_MANIPULATOR_RIGHT2);
        frc::Solenoid clawSolLeft2 = frc::Solenoid(PCM_CAN_ID, PCM_BALL_MANIPULATOR_LEFT2);

        PCMHandler();
    public:
        static PCMHandler* getInstance() {
            static PCMHandler instance;

            return &instance;           
        }

        PCMHandler(PCMHandler const&) = delete;
        void operator = (PCMHandler const&) = delete;

        void turnOn();
        void turnOff();
        void setLowGear();
        void setHighGear();
        void openManipulator();
        void closeManipulator();
};