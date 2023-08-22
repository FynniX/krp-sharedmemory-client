//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceSessionStateInfo.h"
#include "RaceSessionStateInfoWorker.h"

RaceSessionStateInfoWorker::RaceSessionStateInfoWorker(Napi::Function &callback, RaceSessionStateInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceSessionStateInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceSessionStateInfoWorker::OnOK() {
    RaceSessionStateInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
parsed.Set("m_id", data.m_id);
Napi::Object m_RaceSessionState = Napi::Object::New(Env());
m_RaceSessionState.Set("m_iSession", data.m_RaceSessionState.m_iSession);
m_RaceSessionState.Set("m_iSessionSeries", data.m_RaceSessionState.m_iSessionSeries);
m_RaceSessionState.Set("m_iSessionState", data.m_RaceSessionState.m_iSessionState);
m_RaceSessionState.Set("m_iSessionLength", data.m_RaceSessionState.m_iSessionLength);
m_RaceSessionState.Freeze();
parsed.Set("m_RaceSessionState", m_RaceSessionState);
parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}