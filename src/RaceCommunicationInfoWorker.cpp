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

void RaceCommunicationInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceCommunicationInfoWorker::OnOK() {
    RaceCommunicationInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
parsed.Set("m_id", data.m_id);
Napi::Object m_RaceCommunication = Napi::Object::New(Env());
m_RaceCommunication.Set("m_iSession", data.m_RaceCommunication.m_iSession);
m_RaceCommunication.Set("m_iSessionSeries", data.m_RaceCommunication.m_iSessionSeries);
m_RaceCommunication.Set("m_iRaceNum", data.m_RaceCommunication.m_iRaceNum);
m_RaceCommunication.Set("m_iCommunication", data.m_RaceCommunication.m_iCommunication);
m_RaceCommunication.Set("m_iState", data.m_RaceCommunication.m_iState);
m_RaceCommunication.Set("m_iReason", data.m_RaceCommunication.m_iReason);
m_RaceCommunication.Set("m_iOffence", data.m_RaceCommunication.m_iOffence);
m_RaceCommunication.Set("m_iLap", data.m_RaceCommunication.m_iLap);
m_RaceCommunication.Set("m_iType", data.m_RaceCommunication.m_iType);
m_RaceCommunication.Set("m_iTime", data.m_RaceCommunication.m_iTime);
m_RaceCommunication.Freeze();
parsed.Set("m_RaceCommunication", m_RaceCommunication);
parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}