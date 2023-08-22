//
// Created by Fynn Haupt on 18.06.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "RaceSessionInfo.h"

void RaceSessionInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

RaceSessionInfo_t *RaceSessionInfo::getView() {
    return this->controller.view();
}

void RaceSessionInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string RaceSessionInfo::waitForChange() {
    if (!this->isConnected) return "RaceSessionInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "RaceSessionInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}
