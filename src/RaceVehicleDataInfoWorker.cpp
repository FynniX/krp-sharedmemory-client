//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceVehicleDataInfo.h"
#include "RaceVehicleDataInfoWorker.h"

RaceVehicleDataInfoWorker::RaceVehicleDataInfoWorker(Napi::Function &callback, RaceVehicleDataInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceVehicleDataInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceVehicleDataInfoWorker::OnOK() {
    RaceVehicleDataInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
parsed.Set("m_id", data.m_id);
Napi::Object m_RaceVehicleData = Napi::Object::New(Env());
m_RaceVehicleData.Set("m_iRaceNum", data.m_RaceVehicleData.m_iRaceNum);
m_RaceVehicleData.Set("m_iActive", data.m_RaceVehicleData.m_iActive);
m_RaceVehicleData.Set("m_iRPM", data.m_RaceVehicleData.m_iRPM);
m_RaceVehicleData.Set("m_iGear", data.m_RaceVehicleData.m_iGear);
m_RaceVehicleData.Set("m_fSpeedometer", data.m_RaceVehicleData.m_fSpeedometer);
m_RaceVehicleData.Set("m_fSteer", data.m_RaceVehicleData.m_fSteer);
m_RaceVehicleData.Set("m_fThrottle", data.m_RaceVehicleData.m_fThrottle);
m_RaceVehicleData.Set("m_fBrake", data.m_RaceVehicleData.m_fBrake);
m_RaceVehicleData.Freeze();
parsed.Set("m_RaceVehicleData", m_RaceVehicleData);
parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}