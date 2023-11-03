//
// Created by Fynn Haupt on 02.11.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "CameraInfo.h"
#include "CameraInfoWorker.h"

CameraInfoWorker::CameraInfoWorker(Napi::Function &callback, CameraInfo &info)
    : AsyncWorker(callback), info(info) {}

void CameraInfoWorker::Execute()
{
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "")
    {
        SetError(errorMessage);
        return;
    }
}

void CameraInfoWorker::OnOK()
{
    CameraInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);

    Napi::Object m_VehiclesInfo = Napi::Object::New(Env());
    m_VehiclesInfo.Set("_iNumVehicles", data.m_VehiclesInfo._iNumVehicles);
    m_VehiclesInfo.Set("_iCurSelection", data.m_VehiclesInfo._iCurSelection);

    Napi::Array m_VehicleDataArr = Napi::Array::New(Env(), GetArrayLength(data.m_VehiclesInfo.m_VehicleData));
    for (int i = 0; i < GetArrayLength(data.m_VehiclesInfo.m_VehicleData); i++)
    {
        Napi::Object m_VehicleData = Napi::Object::New(Env());
        m_VehicleData.Set("m_iRaceNum", data.m_VehiclesInfo.m_VehicleData[i].m_iRaceNum);
        m_VehicleData.Set("m_szName", GetStringFromChar(data.m_VehiclesInfo.m_VehicleData[i].m_szName));
        m_VehicleData.Freeze();
        m_VehicleDataArr[i] = m_VehicleData;
    }
    m_VehiclesInfo.Set("m_VehicleData", m_VehicleDataArr);

    m_VehiclesInfo.Freeze();
    parsed.Set("m_VehiclesInfo", m_VehiclesInfo);

    Napi::Object m_CamerasInfo = Napi::Object::New(Env());
    m_CamerasInfo.Set("_iNumCameras", data.m_CamerasInfo._iNumCameras);
    m_CamerasInfo.Set("_iCurSelection", data.m_CamerasInfo._iCurSelection);

    Napi::Array m_CameraNames = Napi::Array::New(Env(), GetArrayLength(data.m_CamerasInfo.m_CameraNames));
    for (int i = 0; i < GetArrayLength(data.m_CamerasInfo.m_CameraNames); i++)
        m_CameraNames[i] = GetStringFromChar(data.m_CamerasInfo.m_CameraNames[i]);
    m_CamerasInfo.Set("m_CameraNames", m_CameraNames);

    m_CamerasInfo.Freeze();
    parsed.Set("m_CamerasInfo", m_CamerasInfo);

    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}