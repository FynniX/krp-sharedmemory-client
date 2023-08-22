//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceTrackPositionInfo.h"
#include "RaceTrackPositionInfoWorker.h"

RaceTrackPositionInfoWorker::RaceTrackPositionInfoWorker(Napi::Function &callback, RaceTrackPositionInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceTrackPositionInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceTrackPositionInfoWorker::OnOK() {
    RaceTrackPositionInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
parsed.Set("m_id", data.m_id);
parsed.Set("_iNumVehicles", data._iNumVehicles);
Napi::Array m_RaceTrackPositions = Napi::Array::New(Env(), GetArrayLength(data.m_RaceTrackPositions));
for (int i1 = 0; i1 < GetArrayLength(data.m_RaceTrackPositions); i1++) {
Napi::Object obj = Napi::Object::New(Env());
obj.Set("m_iRaceNum", data.m_RaceTrackPositions[i1].m_iRaceNum);
obj.Set("m_fPosX", data.m_RaceTrackPositions[i1].m_fPosX);
obj.Set("m_fPosY", data.m_RaceTrackPositions[i1].m_fPosY);
obj.Set("m_fPosZ", data.m_RaceTrackPositions[i1].m_fPosZ);
obj.Set("m_fYaw", data.m_RaceTrackPositions[i1].m_fYaw);
obj.Set("m_fTrackPos", data.m_RaceTrackPositions[i1].m_fTrackPos);
obj.Freeze();
m_RaceTrackPositions[i1] = obj;
}
parsed.Set("m_RaceTrackPositions", m_RaceTrackPositions);
parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}