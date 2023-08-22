//
// Created by Fynn Haupt on 16.06.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "PluginInfo.h"

void PluginInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

PluginInfo_t *PluginInfo::getView() {
    return this->controller.view();
}

void PluginInfo::disconnect() {
    if (!this->isConnected) return;
    this->controller.close();
    this->lastId = -1;
    this->isConnected = false;
}

std::string PluginInfo::waitForChange() {
    if (!this->isConnected) return "PlayerInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}
