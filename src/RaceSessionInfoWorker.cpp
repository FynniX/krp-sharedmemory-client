//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceSessionInfo.h"
#include "RaceSessionInfoWorker.h"

RaceSessionInfoWorker::RaceSessionInfoWorker(Napi::Function &callback, RaceSessionInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceSessionInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceSessionInfoWorker::OnOK() {
    RaceSessionInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_RaceSession = Napi::Object::New(Env());
    m_RaceSession.Set("m_iSession", data.m_RaceSession.m_iSession);
    m_RaceSession.Set("m_iSessionSeries", data.m_RaceSession.m_iSessionSeries);
    m_RaceSession.Set("m_iGroup1", data.m_RaceSession.m_iGroup1);
    m_RaceSession.Set("m_iGroup2", data.m_RaceSession.m_iGroup2);
    m_RaceSession.Set("m_iSessionState", data.m_RaceSession.m_iSessionState);
    m_RaceSession.Set("m_iSessionLength", data.m_RaceSession.m_iSessionLength);
    m_RaceSession.Set("m_iSessionNumLaps", data.m_RaceSession.m_iSessionNumLaps);
    m_RaceSession.Set("m_iNumEntries", data.m_RaceSession.m_iNumEntries);
    Napi::Array m_aiEntries = Napi::Array::New(Env(), GetArrayLength(data.m_RaceSession.m_aiEntries));
    for (int i = 0; i < GetArrayLength(data.m_RaceSession.m_aiEntries); i++)
        m_aiEntries[i] = data.m_RaceSession.m_aiEntries[i];
    m_RaceSession.Set("m_aiEntries", m_aiEntries);
    Napi::Array m_aiGrid = Napi::Array::New(Env(), GetArrayLength(data.m_RaceSession.m_aiGrid));
    for (int i = 0; i < GetArrayLength(data.m_RaceSession.m_aiGrid); i++)
        m_aiGrid[i] = data.m_RaceSession.m_aiGrid[i];
    m_RaceSession.Set("m_aiGrid", m_aiGrid);
    m_RaceSession.Set("m_iConditions", data.m_RaceSession.m_iConditions);
    m_RaceSession.Set("m_fAirTemperature", data.m_RaceSession.m_fAirTemperature);
    m_RaceSession.Set("m_fTrackTemperature", data.m_RaceSession.m_fTrackTemperature);
    m_RaceSession.Freeze();
    parsed.Set("m_RaceSession", m_RaceSession);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}