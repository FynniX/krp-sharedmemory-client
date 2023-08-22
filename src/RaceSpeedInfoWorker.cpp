//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceSpeedInfo.h"
#include "RaceSpeedInfoWorker.h"

RaceSpeedInfoWorker::RaceSpeedInfoWorker(Napi::Function &callback, RaceSpeedInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceSpeedInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceSpeedInfoWorker::OnOK() {
    RaceSpeedInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_RaceSpeed = Napi::Object::New(Env());
    m_RaceSpeed.Set("m_iSession", data.m_RaceSpeed.m_iSession);
    m_RaceSpeed.Set("m_iSessionSeries", data.m_RaceSpeed.m_iSessionSeries);
    m_RaceSpeed.Set("m_iRaceNum", data.m_RaceSpeed.m_iRaceNum);
    m_RaceSpeed.Set("m_iLapNum", data.m_RaceSpeed.m_iLapNum);
    m_RaceSpeed.Set("m_fSpeed", data.m_RaceSpeed.m_fSpeed);
    m_RaceSpeed.Freeze();
    parsed.Set("m_RaceSpeed", m_RaceSpeed);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}