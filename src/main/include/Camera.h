
#pragma once

#include <frc/WPILib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class Camera {
    public:
        Camera();
        void VisionThread(int resolutionX, int resolutionY);
        cs::UsbCamera getCamera();

    private:
        cs::UsbCamera camera;
        cs::CvSink cvSink;
        cs::CvSource outputStreamStd;
        cv::Mat source;
};