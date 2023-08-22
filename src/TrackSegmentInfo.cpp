//
// Created by Fynn Haupt on 18.06.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "TrackSegmentInfo.h"

void TrackSegmentInfo::connect() {
    if (this->isConnected) return;

    try {
        this->controller.open();
    } catch (std::runtime_error e) {
        return;
    }

    this->isConnected = true;
}

TrackSegmentInfo_t *TrackSegmentInfo::getView() {
    return this->controller.view();
}

void TrackSegmentInfo::disconnect() {
    if (!this->isConnected) return;
    this->lastId = -1;
    this->isConnected = false;
    this->controller.close();
}

std::string TrackSegmentInfo::waitForChange() {
    if (!this->isConnected) return "TrackSegmentInfo is not connected!";
    int id = this->getView()->m_id;

    while (id == this->lastId) {
        Sleep(this->waitDelay);
        if (!this->isConnected) return "TrackSegmentInfo is not connected!";
        id = this->getView()->m_id;
    }

    this->lastId = id;
    return "";
}
