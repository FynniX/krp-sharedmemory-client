//
// Created by Fynn Haupt on 02.11.2023.
//
#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "CameraInfo.h"

void CameraInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

CameraInfo_t *CameraInfo::getView() {
    return this->controller.view();
}

void CameraInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string CameraInfo::waitForChange() {
    if (!this->isConnected) return "CameraInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "CameraInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}