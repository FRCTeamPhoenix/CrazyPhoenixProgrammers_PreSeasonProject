#include "Pixy.h"
#include <iostream>



void Pixy::getVersion() {

    uint8_t command[]={0xae, 0xc1, 0x0e, 0x00};
    m_connection.Write(command, sizeof(command));
    uint8_t buffer;
    while(!m_connection.Read(false, &buffer, 1)) {

        std::cout<<buffer<<std::endl;
    }
    
}

void Pixy::init() {

    m_connection.SetMSBFirst();

}

void Pixy::getBlocks() {



}
Pixy::Pixy() {}