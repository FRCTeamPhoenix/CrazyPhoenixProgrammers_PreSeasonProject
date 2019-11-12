
#pragma once

#include <sstream>

#include "WPILib.h"
#include <frc/I2C.h>
#include <frc/PIDSource.h>

class Lidar : public frc::PIDSource {
    public:
        Lidar(frc::I2C::Port port);
        void startMeasuring();
        void stopMeasuring();
        int getDistance();
        void setPIDSourceType(frc::PIDSourceType pidSource);
        frc::PIDSourceType getPIDSourceType();
        double pidGet();
    
    private:
        frc::I2C m_i2c;
        int writeRegister(int address, int value);
        short readShort(int address);
        const static uint8_t k_deviceAddress = 0x62;
        unsigned char m_port;
        std::stringbuf m_buffer;
}