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

void RaceVehicleDataInfoWorker::Execute()
{
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "")
    {
        SetError(errorMessage);
        return;
    }
}

void RaceVehicleDataInfoWorker::OnOK()
{
    RaceVehicleDataInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);

    Napi::Array m_RaceVehicleDatas = Napi::Array::New(Env(), GetArrayLength(data.m_RaceVehicleDatas));
    for (int i1 = 0; i1 < GetArrayLength(data.m_RaceVehicleDatas); i1++)
    {
        Napi::Object m_RaceVehicleData = Napi::Object::New(Env());
        m_RaceVehicleData.Set("m_iRaceNum", data.m_RaceVehicleDatas[i1].m_iRaceNum);
        m_RaceVehicleData.Set("m_iActive", data.m_RaceVehicleDatas[i1].m_iActive);
        m_RaceVehicleData.Set("m_iRPM", data.m_RaceVehicleDatas[i1].m_iRPM);
        m_RaceVehicleData.Set("m_iGear", data.m_RaceVehicleDatas[i1].m_iGear);
        m_RaceVehicleData.Set("m_fSpeedometer", data.m_RaceVehicleDatas[i1].m_fSpeedometer);
        m_RaceVehicleData.Set("m_fSteer", data.m_RaceVehicleDatas[i1].m_fSteer);
        m_RaceVehicleData.Set("m_fThrottle", data.m_RaceVehicleDatas[i1].m_fThrottle);
        m_RaceVehicleData.Set("m_fBrake", data.m_RaceVehicleDatas[i1].m_fBrake);
        m_RaceVehicleData.Freeze();
        m_RaceVehicleDatas[i1] = m_RaceVehicleData;
    }
    parsed.Set("m_RaceVehicleDatas", m_RaceVehicleDatas);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}