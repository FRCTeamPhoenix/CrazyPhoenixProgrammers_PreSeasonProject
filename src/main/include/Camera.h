
#pragma once

#include <frc/WPILib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class Camera {
    public:
        Camera();
        void StartThread();
        cs::UsbCamera getCamera();

    private:
        static void VisionThread();
};
