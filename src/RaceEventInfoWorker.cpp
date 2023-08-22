//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceEventInfo.h"
#include "RaceEventInfoWorker.h"

RaceEventInfoWorker::RaceEventInfoWorker(Napi::Function &callback, RaceEventInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceEventInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceEventInfoWorker::OnOK() {
    RaceEventInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_RaceEvent = Napi::Object::New(Env());
    m_RaceEvent.Set("m_iType", data.m_RaceEvent.m_iType);
    m_RaceEvent.Set("m_szName", GetStringFromChar(data.m_RaceEvent.m_szName));
    m_RaceEvent.Set("m_szTrackName", GetStringFromChar(data.m_RaceEvent.m_szTrackName));
    m_RaceEvent.Set("m_fTrackLength", data.m_RaceEvent.m_fTrackLength);
    m_RaceEvent.Freeze();
    parsed.Set("m_RaceEvent", m_RaceEvent);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}