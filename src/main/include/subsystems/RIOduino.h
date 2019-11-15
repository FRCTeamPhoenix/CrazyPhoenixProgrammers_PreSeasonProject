
#pragma once

#include "WPILib.h"
#include <frc/SerialPort.h>
#include <frc/Timer.h>

class RIOduino {
    public:
        RIOduino();
        double getDistanceIn();
        int getDistanceCm();
        double getFDistanceIn();
        int getFDistanceCm();
        double getSDistanceIn();
        int getSDistanceCm();
        void start();
        void stop();
    
    private:
        const frc::SerialPort LIDAR_PORT = frc::SerialPort::Port::kMXP;
        const int SLOW_AVERAGE_SIZE = 25;
        const int FAST_AVERAGE_SIZE = 10;
        const int NUM_SAMPLES = 10;
        const int SERIAL_BAUD_RATE = 115200;
        const double CM_TO_IN = 0.393701;
        
        frc::SerialPort m_port;
        frc::Timer m_updater;
        int m_distance;
        int m_faverage;
        int m_saverage;
        int m_distances[];

        void update();
}