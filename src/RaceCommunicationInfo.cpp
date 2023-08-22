//
// Created by Fynn Haupt on 18.06.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "RaceCommunicationInfo.h"

void RaceCommunicationInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

RaceCommunicationInfo_t *RaceCommunicationInfo::getView() {
    return this->controller.view();
}

void RaceCommunicationInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string RaceCommunicationInfo::waitForChange() {
    if (!this->isConnected) return "RaceCommunicationInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "RaceCommunicationInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}
