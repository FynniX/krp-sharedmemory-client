#include "KartTelemetryInfo.h"

Napi::Value KartTelemetryInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_fTime", view->_fTime);
    obj.Set("_fPos", view->_fPos);

    // m_KartData
    Napi::Object m_KartData = Napi::Object::New(env);
    m_KartData.Set("m_iRPM", view->m_KartData.m_iRPM);
    m_KartData.Set("m_fCylinderHeadTemperature", view->m_KartData.m_fCylinderHeadTemperature);
    m_KartData.Set("m_fWaterTemperature", view->m_KartData.m_fWaterTemperature);
    m_KartData.Set("m_iGear", view->m_KartData.m_iGear);
    m_KartData.Set("m_fFuel", view->m_KartData.m_fFuel);
    m_KartData.Set("m_fSpeedometer", view->m_KartData.m_fSpeedometer);
    m_KartData.Set("m_fPosX", view->m_KartData.m_fPosX);
    m_KartData.Set("m_fPosY", view->m_KartData.m_fPosY);
    m_KartData.Set("m_fPosZ", view->m_KartData.m_fPosZ);
    m_KartData.Set("m_fVelocityX", view->m_KartData.m_fVelocityX);
    m_KartData.Set("m_fVelocityY", view->m_KartData.m_fVelocityY);
    m_KartData.Set("m_fVelocityZ", view->m_KartData.m_fVelocityZ);
    m_KartData.Set("m_fAccelerationX", view->m_KartData.m_fAccelerationX);
    m_KartData.Set("m_fAccelerationY", view->m_KartData.m_fAccelerationY);
    m_KartData.Set("m_fAccelerationZ", view->m_KartData.m_fAccelerationZ);
    Napi::Array m_aafRot = Napi::Array::New(env, GetArrayLength(view->m_KartData.m_aafRot));
    for (int i = 0; i < GetArrayLength(view->m_KartData.m_aafRot); i++)
    {
        Napi::Array arr = Napi::Array::New(env, GetArrayLength(view->m_KartData.m_aafRot[i]));
        for (int j = 0; j < GetArrayLength(view->m_KartData.m_aafRot[i]); j++)
            arr[j] = view->m_KartData.m_aafRot[i][j];
        m_aafRot[i] = arr;
    }
    m_KartData.Set("m_aafRot", m_aafRot);
    m_KartData.Set("m_fYaw", view->m_KartData.m_fYaw);
    m_KartData.Set("m_fPitch", view->m_KartData.m_fPitch);
    m_KartData.Set("m_fRoll", view->m_KartData.m_fRoll);
    m_KartData.Set("m_fYawVelocity", view->m_KartData.m_fYawVelocity);
    m_KartData.Set("m_fPitchVelocity", view->m_KartData.m_fPitchVelocity);
    m_KartData.Set("m_fRollVelocity", view->m_KartData.m_fRollVelocity);
    m_KartData.Set("m_fInputSteer", view->m_KartData.m_fInputSteer);
    m_KartData.Set("m_fInputThrottle", view->m_KartData.m_fInputThrottle);
    m_KartData.Set("m_fInputBrake", view->m_KartData.m_fInputBrake);
    m_KartData.Set("m_fInputFrontBrakes", view->m_KartData.m_fInputFrontBrakes);
    m_KartData.Set("m_fInputClutch", view->m_KartData.m_fInputClutch);
    Napi::Array m_afWheelSpeed = Napi::Array::New(env, GetArrayLength(view->m_KartData.m_afWheelSpeed));
    for (int i = 0; i < GetArrayLength(view->m_KartData.m_afWheelSpeed); i++)
        m_afWheelSpeed[i] = view->m_KartData.m_afWheelSpeed[i];
    m_KartData.Set("m_afWheelSpeed", m_afWheelSpeed);
    Napi::Array m_aiWheelMaterial = Napi::Array::New(env, GetArrayLength(view->m_KartData.m_aiWheelMaterial));
    for (int i = 0; i < GetArrayLength(view->m_KartData.m_aiWheelMaterial); i++)
        m_aiWheelMaterial[i] = view->m_KartData.m_aiWheelMaterial[i];
    m_KartData.Set("m_aiWheelMaterial", m_aiWheelMaterial);
    m_KartData.Set("m_fSteerTorque", view->m_KartData.m_fSteerTorque);
    m_KartData.Freeze();

    obj.Set("m_KartData", m_KartData);
    obj.Freeze();

    return obj;
}