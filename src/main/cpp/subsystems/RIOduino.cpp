
#include "subsystems/RIOduino.h"

#include <iostream>
#include <string>
#include <regex>

RIOduino::RIOduino() {
    m_distance = 1;
    m_port = new frc::SerialPort(SERIAL_BAUD_RATE, LIDAR_PORT);
    m_updater = new frc::Timer();
    m_distances = new int[SLOW_AVERAGE_SIZE];
    m_faverage = 1;
    m_saverage = 1;

    for (int i = 0; i <= m_distances.length; i++)
        m_distances[i] = 0;
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
    m_port.WriteString("H");
    frc::Timer.wait(0.06);
    std::string revc = m_port.readString();
    std::cout << revc << "r" << std::endl;

    int startChar = recv.indexOf('s');
    int endChar = -1;
    
    if(startChar != -1)
        endChar = recv.indexOf('\n',startChar);
    else
        return;
    if(startChar == -1 || endChar == -1 || startChar > endChar)
        return;
    
    std::string finalString = recv.substring(startChar + 1, endChar - 1);
    std::regex r("[^0-9.]");

    
    std::string lidar = revc;
    std::regex_replace(lidar, r, "");
    m_distance = std::stoi(lidar);
    
}