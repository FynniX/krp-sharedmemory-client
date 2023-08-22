//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "KartSessionInfo.h"
#include "KartSessionInfoWorker.h"

KartSessionInfoWorker::KartSessionInfoWorker(Napi::Function &callback, KartSessionInfo &info)
        : AsyncWorker(callback), info(info) {}

void KartSessionInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void KartSessionInfoWorker::OnOK() {
    KartSessionInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_KartSession = Napi::Object::New(Env());
    m_KartSession.Set("m_iSession", data.m_KartSession.m_iSession);
    m_KartSession.Set("m_iSessionSeries", data.m_KartSession.m_iSessionSeries);
    m_KartSession.Set("m_iConditions", data.m_KartSession.m_iConditions);
    m_KartSession.Set("m_fAirTemperature", data.m_KartSession.m_fAirTemperature);
    m_KartSession.Set("m_fTrackTemperature", data.m_KartSession.m_fTrackTemperature);
    m_KartSession.Set("m_szSetupFileName", GetStringFromChar(data.m_KartSession.m_szSetupFileName));
    m_KartSession.Freeze();
    parsed.Set("m_KartSession", m_KartSession);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}