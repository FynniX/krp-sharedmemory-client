//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceLapInfo.h"
#include "RaceLapInfoWorker.h"

RaceLapInfoWorker::RaceLapInfoWorker(Napi::Function &callback, RaceLapInfo &info)
    : AsyncWorker(callback), info(info) {}

void RaceLapInfoWorker::Execute()
{
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "")
    {
        SetError(errorMessage);
        return;
    }
}

void RaceLapInfoWorker::OnOK()
{
    RaceLapInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);

    Napi::Array m_RaceLaps = Napi::Array::New(Env(), GetArrayLength(data.m_RaceLaps));
    for (int i1 = 0; i1 < GetArrayLength(data.m_RaceLaps); i1++)
    {
        Napi::Object m_RaceLap = Napi::Object::New(Env());
        m_RaceLap.Set("m_iSession", data.m_RaceLaps[i1].m_iSession);
        m_RaceLap.Set("m_iSessionSeries", data.m_RaceLaps[i1].m_iSessionSeries);
        m_RaceLap.Set("m_iRaceNum", data.m_RaceLaps[i1].m_iRaceNum);
        m_RaceLap.Set("m_iLapNum", data.m_RaceLaps[i1].m_iLapNum);
        m_RaceLap.Set("m_iInvalid", data.m_RaceLaps[i1].m_iInvalid);
        m_RaceLap.Set("m_iLapTime", data.m_RaceLaps[i1].m_iLapTime);
        Napi::Array m_aiSplit = Napi::Array::New(Env(), GetArrayLength(data.m_RaceLaps[i1].m_aiSplit));
        for (int i = 0; i < GetArrayLength(data.m_RaceLaps[i1].m_aiSplit); i++)
            m_aiSplit[i] = data.m_RaceLaps[i1].m_aiSplit[i];
        m_RaceLap.Set("m_aiSplit", m_aiSplit);
        m_RaceLap.Set("m_fSpeed", data.m_RaceLaps[i1].m_fSpeed);
        m_RaceLap.Set("m_iBest", data.m_RaceLaps[i1].m_iBest);
        m_RaceLap.Freeze();
        m_RaceLaps[i1] = m_RaceLap;
    }
    parsed.Set("m_RaceLaps", m_RaceLaps);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}