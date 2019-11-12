
#include "subsystems/Lidar.h"

Lidar::Lidar(frc::I2C::Port port) {
    m_i2c = frc::I2C(frc::I2C::Port::kMXP, 0x62);
    m_port = (unsigned char) port;
}

void Lidar::startMeasuring() {
    writeRegister(0x04, 0x08 | 32); // default plus bit 5
    writeRegister(0x11, 0xff);
    writeRegister(0x00, 0x04);
}

void Lidar::stopMeasuring() {
    writeRegister(0x11, 0x00);
}

int Lidar::getDistance() {
    return readShort(0x8f);
}

int Lidar::writeRegister(int address, int value) {
    m_buffer.sputn(0, (unsigned char) address);
    m_buffer.sputn((const char*) 1, (unsigned char) value);

    return m_i2c.Write(m_port, k_deviceAddress);
}

short Lidar::readShort(int address) {
		m_buffer.sputn(0, (unsigned char) address);
		m_i2c.Write(m_port, k_deviceAddress);
		m_i2c.Read(m_port, 1, &k_deviceAddress);
		return m_buffer.getShort(0);
}

void Lidar::setPIDSourceType(frc::PIDSourceType pidSource) {
    if (pidSource != frc::PIDSourceType::kDisplacement) {
        throw new std::invalid_argument("Only displacement is supported");
    }
}

frc::PIDSourceType Lidar::getPIDSourceType() {
    return frc::PIDSourceType::kDisplacement;
}

double Lidar::pidGet() {
    return getDistance();
}