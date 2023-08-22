//
// Created by Fynn Haupt on 18.06.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "KartSessionInfo.h"

void KartSessionInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

KartSessionInfo_t *KartSessionInfo::getView() {
    return this->controller.view();
}

void KartSessionInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string KartSessionInfo::waitForChange() {
    if (!this->isConnected) return "KartSessionInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "KartSessionInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}
