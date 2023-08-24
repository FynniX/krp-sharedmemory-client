//
// Created by Fynn Haupt on 24.08.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "RaceEntriesInfo.h"

void RaceEntriesInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

RaceEntriesInfo_t *RaceEntriesInfo::getView() {
    return this->controller.view();
}

void RaceEntriesInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string RaceEntriesInfo::waitForChange() {
    if (!this->isConnected) return "RaceEntriesInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "RaceEntriesInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}