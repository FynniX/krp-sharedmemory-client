//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceClassificationInfo.h"
#include "RaceClassificationInfoWorker.h"

RaceClassificationInfoWorker::RaceClassificationInfoWorker(Napi::Function &callback, RaceClassificationInfo &info)
    : AsyncWorker(callback), info(info) {}

void RaceClassificationInfoWorker::Execute()
{
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "")
    {
        SetError(errorMessage);
        return;
    }
}

void RaceClassificationInfoWorker::OnOK()
{
    RaceClassificationInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_RaceClassification = Napi::Object::New(Env());
    m_RaceClassification.Set("m_iSession", data.m_RaceClassification.m_iSession);
    m_RaceClassification.Set("m_iSessionSeries", data.m_RaceClassification.m_iSessionSeries);
    m_RaceClassification.Set("m_iSessionState", data.m_RaceClassification.m_iSessionState);
    m_RaceClassification.Set("m_iSessionTime", data.m_RaceClassification.m_iSessionTime);
    m_RaceClassification.Set("m_iNumEntries", data.m_RaceClassification.m_iNumEntries);
    m_RaceClassification.Freeze();
    parsed.Set("m_RaceClassification", m_RaceClassification);
    Napi::Array m_RaceEntries = Napi::Array::New(Env(), GetArrayLength(data.m_RaceEntries));
    for (int i1 = 0; i1 < GetArrayLength(data.m_RaceEntries); i1++)
    {
        Napi::Object obj = Napi::Object::New(Env());
        obj.Set("m_iRaceNum", data.m_RaceEntries[i1].m_iRaceNum);
        obj.Set("m_iState", data.m_RaceEntries[i1].m_iState);
        obj.Set("m_iBestLap", data.m_RaceEntries[i1].m_iBestLap);

        Napi::Object m_LastLap = Napi::Object::New(Env());
        m_LastLap.Set("m_iSession", data.m_RaceEntries[i1].m_LastLap.m_iSession);
        m_LastLap.Set("m_iSessionSeries", data.m_RaceEntries[i1].m_LastLap.m_iSessionSeries);
        m_LastLap.Set("m_iRaceNum", data.m_RaceEntries[i1].m_LastLap.m_iRaceNum);
        m_LastLap.Set("m_iLapNum", data.m_RaceEntries[i1].m_LastLap.m_iLapNum);
        m_LastLap.Set("m_iInvalid", data.m_RaceEntries[i1].m_LastLap.m_iInvalid);
        m_LastLap.Set("m_iLapTime", data.m_RaceEntries[i1].m_LastLap.m_iLapTime);

        Napi::Array m_aiSplit = Napi::Array::New(Env(), GetArrayLength(data.m_RaceEntries[i1].m_LastLap.m_aiSplit));
        for (int i = 0; i < GetArrayLength(data.m_RaceEntries[i1].m_LastLap.m_aiSplit); i++)
            m_aiSplit[i] = data.m_RaceEntries[i1].m_LastLap.m_aiSplit[i];
            
        m_LastLap.Set("m_aiSplit", m_aiSplit);
        m_LastLap.Set("m_fSpeed", data.m_RaceEntries[i1].m_LastLap.m_fSpeed);
        m_LastLap.Set("m_iBest", data.m_RaceEntries[i1].m_LastLap.m_iBest);
        m_LastLap.Freeze();

        obj.Set("m_LastLap", m_LastLap);
        obj.Set("m_fBestSpeed", data.m_RaceEntries[i1].m_fBestSpeed);
        obj.Set("m_iBestLapNum", data.m_RaceEntries[i1].m_iBestLapNum);
        obj.Set("m_iNumLaps", data.m_RaceEntries[i1].m_iNumLaps);
        obj.Set("m_iGap", data.m_RaceEntries[i1].m_iGap);
        obj.Set("m_iGapLaps", data.m_RaceEntries[i1].m_iGapLaps);
        obj.Set("m_iPenalty", data.m_RaceEntries[i1].m_iPenalty);
        obj.Set("m_iPit", data.m_RaceEntries[i1].m_iPit);
        obj.Freeze();
        m_RaceEntries[i1] = obj;
    }
    parsed.Set("m_RaceEntries", m_RaceEntries);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}