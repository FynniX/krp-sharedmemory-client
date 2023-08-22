//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "KartEventInfo.h"
#include "KartEventInfoWorker.h"

KartEventInfoWorker::KartEventInfoWorker(Napi::Function &callback, KartEventInfo &info)
        : AsyncWorker(callback), info(info) {}

void KartEventInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void KartEventInfoWorker::OnOK() {
    KartEventInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_KartEvent = Napi::Object::New(Env());
    m_KartEvent.Set("m_szDriverName", GetStringFromChar(data.m_KartEvent.m_szDriverName));
    m_KartEvent.Set("m_szKartID", GetStringFromChar(data.m_KartEvent.m_szKartID));
    m_KartEvent.Set("m_szKartName", GetStringFromChar(data.m_KartEvent.m_szKartName));
    m_KartEvent.Set("m_iDriveType", data.m_KartEvent.m_iDriveType);
    m_KartEvent.Set("m_iNumberOfGears", data.m_KartEvent.m_iNumberOfGears);
    m_KartEvent.Set("m_iMaxRPM", data.m_KartEvent.m_iMaxRPM);
    m_KartEvent.Set("m_iLimiter", data.m_KartEvent.m_iLimiter);
    m_KartEvent.Set("m_iShiftRPM", data.m_KartEvent.m_iShiftRPM);
    m_KartEvent.Set("m_iEngineCooling", data.m_KartEvent.m_iEngineCooling);
    m_KartEvent.Set("m_fEngineOptTemperature", data.m_KartEvent.m_fEngineOptTemperature);
    Napi::Array m_afEngineTemperatureAlarm = Napi::Array::New(Env(), GetArrayLength(
            data.m_KartEvent.m_afEngineTemperatureAlarm));
    for (int i = 0; i < GetArrayLength(data.m_KartEvent.m_afEngineTemperatureAlarm); i++)
        m_afEngineTemperatureAlarm[i] = data.m_KartEvent.m_afEngineTemperatureAlarm[i];
    m_KartEvent.Set("m_afEngineTemperatureAlarm", m_afEngineTemperatureAlarm);
    m_KartEvent.Set("m_fMaxFuel", data.m_KartEvent.m_fMaxFuel);
    m_KartEvent.Set("m_szCategory", GetStringFromChar(data.m_KartEvent.m_szCategory));
    m_KartEvent.Set("m_szDash", GetStringFromChar(data.m_KartEvent.m_szDash));
    m_KartEvent.Set("m_szTrackID", GetStringFromChar(data.m_KartEvent.m_szTrackID));
    m_KartEvent.Set("m_szTrackName", GetStringFromChar(data.m_KartEvent.m_szTrackName));
    m_KartEvent.Set("m_fTrackLength", data.m_KartEvent.m_fTrackLength);
    m_KartEvent.Set("m_iType", data.m_KartEvent.m_iType);
    m_KartEvent.Freeze();
    parsed.Set("m_KartEvent", m_KartEvent);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}