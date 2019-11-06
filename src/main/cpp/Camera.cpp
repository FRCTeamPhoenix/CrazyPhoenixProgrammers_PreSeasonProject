
#include "Camera.h"

Camera::Camera() {
}

void Camera::VisionThread() {
    cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
    camera.SetResolution(640 / 4, 480 / 4);
    cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
    cs::CvSource outputStreamStd = frc::CameraServer::GetInstance()->PutVideo("Gray", 640 / 4, 480 / 4);
    cv::Mat source;

    while (true) {
        cvSink.GrabFrame(source);
        outputStreamStd.PutFrame(source);
    }
}

void Camera::StartThread() {
    std::thread visionThread(VisionThread);
    visionThread.detach();
}
