//
// Created by Fynn Haupt on 18.06.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "KartLapInfo.h"

void KartLapInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

KartLapInfo_t *KartLapInfo::getView() {
    return this->controller.view();
}

void KartLapInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string KartLapInfo::waitForChange() {
    if (!this->isConnected) return "KartLapInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "KartLapInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}
