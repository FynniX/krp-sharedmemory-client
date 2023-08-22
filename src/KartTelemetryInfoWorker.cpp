//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "KartTelemetryInfo.h"
#include "KartTelemetryInfoWorker.h"

KartTelemetryInfoWorker::KartTelemetryInfoWorker(Napi::Function &callback, KartTelemetryInfo &info)
        : AsyncWorker(callback), info(info) {}

void KartTelemetryInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void KartTelemetryInfoWorker::OnOK() {
    KartTelemetryInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
parsed.Set("m_id", data.m_id);
parsed.Set("_fTime", data._fTime);
parsed.Set("_fPos", data._fPos);
Napi::Object m_KartData = Napi::Object::New(Env());
m_KartData.Set("m_iRPM", data.m_KartData.m_iRPM);
m_KartData.Set("m_fCylinderHeadTemperature", data.m_KartData.m_fCylinderHeadTemperature);
m_KartData.Set("m_fWaterTemperature", data.m_KartData.m_fWaterTemperature);
m_KartData.Set("m_iGear", data.m_KartData.m_iGear);
m_KartData.Set("m_fFuel", data.m_KartData.m_fFuel);
m_KartData.Set("m_fSpeedometer", data.m_KartData.m_fSpeedometer);
m_KartData.Set("m_fPosX", data.m_KartData.m_fPosX);
m_KartData.Set("m_fPosY", data.m_KartData.m_fPosY);
m_KartData.Set("m_fPosZ", data.m_KartData.m_fPosZ);
m_KartData.Set("m_fVelocityX", data.m_KartData.m_fVelocityX);
m_KartData.Set("m_fVelocityY", data.m_KartData.m_fVelocityY);
m_KartData.Set("m_fVelocityZ", data.m_KartData.m_fVelocityZ);
m_KartData.Set("m_fAccelerationX", data.m_KartData.m_fAccelerationX);
m_KartData.Set("m_fAccelerationY", data.m_KartData.m_fAccelerationY);
m_KartData.Set("m_fAccelerationZ", data.m_KartData.m_fAccelerationZ);
Napi::Array m_aafRot = Napi::Array::New(Env(), GetArrayLength(data.m_KartData.m_aafRot));
for (int i = 0; i < GetArrayLength(data.m_KartData.m_aafRot); i++) {
Napi::Array arr = Napi::Array::New(Env(), GetArrayLength(data.m_KartData.m_aafRot[i]));
for (int j = 0; j < GetArrayLength(data.m_KartData.m_aafRot[i]); j++)
arr[j] = data.m_KartData.m_aafRot[i][j];
m_aafRot[i] = arr;
}
m_KartData.Set("m_aafRot", m_aafRot);
m_KartData.Set("m_fYaw", data.m_KartData.m_fYaw);
m_KartData.Set("m_fPitch", data.m_KartData.m_fPitch);
m_KartData.Set("m_fRoll", data.m_KartData.m_fRoll);
m_KartData.Set("m_fYawVelocity", data.m_KartData.m_fYawVelocity);
m_KartData.Set("m_fPitchVelocity", data.m_KartData.m_fPitchVelocity);
m_KartData.Set("m_fRollVelocity", data.m_KartData.m_fRollVelocity);
m_KartData.Set("m_fInputSteer", data.m_KartData.m_fInputSteer);
m_KartData.Set("m_fInputThrottle", data.m_KartData.m_fInputThrottle);
m_KartData.Set("m_fInputBrake", data.m_KartData.m_fInputBrake);
m_KartData.Set("m_fInputFrontBrakes", data.m_KartData.m_fInputFrontBrakes);
m_KartData.Set("m_fInputClutch", data.m_KartData.m_fInputClutch);
Napi::Array m_afWheelSpeed = Napi::Array::New(Env(), GetArrayLength(data.m_KartData.m_afWheelSpeed));
for (int i = 0; i < GetArrayLength(data.m_KartData.m_afWheelSpeed); i++)
m_afWheelSpeed[i] = data.m_KartData.m_afWheelSpeed[i];
m_KartData.Set("m_afWheelSpeed", m_afWheelSpeed);
Napi::Array m_aiWheelMaterial = Napi::Array::New(Env(), GetArrayLength(data.m_KartData.m_aiWheelMaterial));
for (int i = 0; i < GetArrayLength(data.m_KartData.m_aiWheelMaterial); i++)
m_aiWheelMaterial[i] = data.m_KartData.m_aiWheelMaterial[i];
m_KartData.Set("m_aiWheelMaterial", m_aiWheelMaterial);
m_KartData.Set("m_fSteerTorque", data.m_KartData.m_fSteerTorque);
m_KartData.Freeze();
parsed.Set("m_KartData", m_KartData);
parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}