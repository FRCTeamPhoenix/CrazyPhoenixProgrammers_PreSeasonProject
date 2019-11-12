
#include "Camera.h"

Camera::Camera() {
}

void Camera::VisionThread() {
    cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    camera.SetResolution(160, 120);
    cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo(camera);
    cs::CvSource outputStreamStd = frc::CameraServer::GetInstance()->PutVideo("Processed: ", 160, 120);
    cv::Mat source;

    while (true) {
        cvSink.GrabFrame(source);
        if(!source.empty())
        {
            outputStreamStd.PutFrame(source);
        }
    }
}

void Camera::StartThread() {
    std::thread visionThread(VisionThread);
    visionThread.detach();
}
