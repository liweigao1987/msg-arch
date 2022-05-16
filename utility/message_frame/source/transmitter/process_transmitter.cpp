//
// Created by liweigao on 17-11-2.
//

#include <iostream>

#include "process_transmitter.h"

ProcessTransmitter::ProcessTransmitter() : Transmitter() {

}

ProcessTransmitter::~ProcessTransmitter() {

}

int ProcessTransmitter::post(std::shared_ptr<Handle> handle) {
    std::cout << "ProcessTransmitter::post" << std::endl;
    return 0;
}
