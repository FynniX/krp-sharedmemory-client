//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "KartLapInfo.h"
#include "KartLapInfoWorker.h"

KartLapInfoWorker::KartLapInfoWorker(Napi::Function &callback, KartLapInfo &info)
        : AsyncWorker(callback), info(info) {}

void KartLapInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void KartLapInfoWorker::OnOK() {
    KartLapInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_KartLap = Napi::Object::New(Env());
    m_KartLap.Set("m_iLapNum", data.m_KartLap.m_iLapNum);
    m_KartLap.Set("m_iInvalid", data.m_KartLap.m_iInvalid);
    m_KartLap.Set("m_iLapTime", data.m_KartLap.m_iLapTime);
    m_KartLap.Set("m_iPos", data.m_KartLap.m_iPos);
    m_KartLap.Freeze();
    parsed.Set("m_KartLap", m_KartLap);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}