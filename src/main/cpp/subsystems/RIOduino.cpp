
#include "subsystems/RIOduino.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <regex>

RIOduino::RIOduino() {
    m_distance = 1;
    m_port = new frc::SerialPort(SERIAL_BAUD_RATE, LIDAR_PORT);
    m_updater = new frc::Timer();
    m_faverage = 1;
    m_saverage = 1;
}

RIOduino::~RIOduino() {
    delete m_port;
    delete m_updater;
}

double RIOduino::getDistanceIn() {
    return CM_TO_IN*m_distance;
}

int RIOduino::getDistanceCm() {
    return m_distance;
}

double RIOduino::getFDistanceIn() {
    return CM_TO_IN*m_faverage;
}

int RIOduino::getFDistanceCm() {
    return m_faverage;
}

double RIOduino::getSDistanceIn() {
    return CM_TO_IN*m_saverage;
}

int RIOduino::getSDistanceCm() {
    return m_saverage;
}

void RIOduino::start() {
    // Create and start a RIOduino thread
}

void RIOduino::update() {
    m_port->Write("H");
    sleep(0.06);
    m_port->Read(m_buffer, MAX_BYTES);
    std::string recv (m_buffer);
    // Ask robert if this is okay
    std::cout << recv << "r" << std::endl;

    int startCharIdx = recv.find("s");
    int endCharIdx = -1;
    
    if(startCharIdx != -1)
        endCharIdx = recv.find("\n", startCharIdx + 1);
    else
        return;
    if(startCharIdx == -1 || endCharIdx == -1 || startCharIdx > endCharIdx)
        return;
    
    std::string finalString = recv.substr(startCharIdx + 1, endCharIdx - 1);
    std::regex r("[^0-9.]");
    std::string lidar = recv;
    std::regex_replace(lidar, r, "");
    m_distance = std::stoi(lidar);

    m_distances[m_distCount % 10] = m_distance;
    m_distCount++;
    
    int locfaverage = 0;
    int locsaverage = 0;

    for (int i = 0; i < FAST_AVERAGE_SIZE; i++)
        locfaverage += m_distances[i];
    for (int i = 0; i < SLOW_AVERAGE_SIZE; i++)
        locsaverage += m_distances[i];
    
    m_faverage = locfaverage / FAST_AVERAGE_SIZE;
    m_saverage = locsaverage / SLOW_AVERAGE_SIZE;

}