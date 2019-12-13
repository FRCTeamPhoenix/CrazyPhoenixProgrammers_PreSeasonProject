#pragma once

#include <frc/SPI.h>

class Pixy {
    public:
        //have a singleton based subsytem since you will only have 1 object


        void init();

        void getBlocks();

        void getVersion();
        Pixy();
    private:

        //CS0 = 0
        frc::SPI m_connection = frc::SPI(frc::SPI::Port(0));
        
};
