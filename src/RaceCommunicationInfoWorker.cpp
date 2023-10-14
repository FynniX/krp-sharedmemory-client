//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceCommunicationInfo.h"
#include "RaceCommunicationInfoWorker.h"

RaceCommunicationInfoWorker::RaceCommunicationInfoWorker(Napi::Function &callback, RaceCommunicationInfo &info)
    : AsyncWorker(callback), info(info) {}

void RaceCommunicationInfoWorker::Execute()
{
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "")
    {
        SetError(errorMessage);
        return;
    }
}

void RaceCommunicationInfoWorker::OnOK()
{
    RaceCommunicationInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);

    Napi::Array m_RaceCommunications = Napi::Array::New(Env(), GetArrayLength(data.m_RaceCommunications));
    for (int i1 = 0; i1 < GetArrayLength(data.m_RaceCommunications); i1++)
    {
        Napi::Object m_RaceCommunication = Napi::Object::New(Env());
        m_RaceCommunication.Set("m_iSession", data.m_RaceCommunications[i1].m_iSession);
        m_RaceCommunication.Set("m_iSessionSeries", data.m_RaceCommunications[i1].m_iSessionSeries);
        m_RaceCommunication.Set("m_iRaceNum", data.m_RaceCommunications[i1].m_iRaceNum);
        m_RaceCommunication.Set("m_iCommunication", data.m_RaceCommunications[i1].m_iCommunication);
        m_RaceCommunication.Set("m_iState", data.m_RaceCommunications[i1].m_iState);
        m_RaceCommunication.Set("m_iReason", data.m_RaceCommunications[i1].m_iReason);
        m_RaceCommunication.Set("m_iOffence", data.m_RaceCommunications[i1].m_iOffence);
        m_RaceCommunication.Set("m_iLap", data.m_RaceCommunications[i1].m_iLap);
        m_RaceCommunication.Set("m_iType", data.m_RaceCommunications[i1].m_iType);
        m_RaceCommunication.Set("m_iTime", data.m_RaceCommunications[i1].m_iTime);
        m_RaceCommunication.Freeze();
        m_RaceCommunications[i1] = m_RaceCommunication;
    }
    parsed.Set("m_RaceCommunications", m_RaceCommunications);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}