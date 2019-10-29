#include "PCM.h"

    void PCMHandler::turnOn() { 
        compressor.SetClosedLoopControl(true);
    }

    void PCMHandler::turnOff() {
        compressor.SetClosedLoopControl(false);
    }

    void PCMHandler::setLowGear() {
        highgearSol.Set(false);
        lowgearSol.Set(true);
    }

    void PCMHandler::setHighGear() {
        lowgearSol.Set(false);
        highgearSol.Set(true);
    }

    void PCMHandler::openManipulator() {
        clawSolLeft.Set(false);
        clawSolRight.Set(false);
        clawSolLeft2.Set(true);
        clawSolRight2.Set(true);
    }

    void PCMHandler::closeManipulator() {
        clawSolLeft.Set(true);
        clawSolRight.Set(true);
        clawSolLeft2.Set(false);
        clawSolRight2.Set(false);
    }

    PCMHandler::PCMHandler() {}  
