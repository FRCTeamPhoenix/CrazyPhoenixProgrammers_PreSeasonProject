
#pragma once

#include <frc/WPILib.h>
#include <frc/SerialPort.h>
#include <frc/Timer.h>

class RIOduino {
    public:
        RIOduino();
        ~RIOduino();
        double getDistanceIn();
        int getDistanceCm();
        double getFDistanceIn();
        int getFDistanceCm();
        double getSDistanceIn();
        int getSDistanceCm();
        void start();
        void stop();
    
    private:
        const frc::SerialPort::Port LIDAR_PORT = frc::SerialPort::Port::kMXP;
        const static int SLOW_AVERAGE_SIZE = 25;
        const static int FAST_AVERAGE_SIZE = 10;
        const int NUM_SAMPLES = 10;
        const int SERIAL_BAUD_RATE = 115200;
        const int MAX_BYTES = 8;
        const double CM_TO_IN = 0.393701;
        
        frc::SerialPort *m_port;
        frc::Timer *m_updater;
        int m_distance;
        int m_faverage;
        int m_saverage;
        int m_distances[SLOW_AVERAGE_SIZE] = {0, 0, 0, 0, 0};
        int m_distCount = 0;
        char* m_buffer;

        void update();
};