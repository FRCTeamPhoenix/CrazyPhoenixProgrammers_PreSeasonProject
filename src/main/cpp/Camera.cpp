
#include "Camera.h"

Camera::Camera() {
}

void Camera::VisionThread(int resolutionX, int resolutionY) {
    camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
    camera.SetResolution(resolutionX, resolutionY);
    cvSink = frc::CameraServer::GetInstance()->GetVideo();
    outputStreamStd = frc::CameraServer::GetInstance()->PutVideo("Gray", resolutionX, resolutionY);

    while (true) {
        cvSink.GrabFrame(source);
        outputStreamStd.PutFrame(source);
    }
}

cs::UsbCamera Camera::getCamera() {
    return camera;
}
