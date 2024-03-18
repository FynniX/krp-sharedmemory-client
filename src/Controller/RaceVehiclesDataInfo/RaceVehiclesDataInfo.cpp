#include "RaceVehiclesDataInfo.h"

Napi::Value RaceVehiclesDataInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    
    // m_KartEvent
    Napi::Array m_RaceVehiclesData = Napi::Array::New(env, GetArrayLength(view->m_RaceVehiclesData));
    for (int i1 = 0; i1 < GetArrayLength(view->m_RaceVehiclesData); i1++)
    {
        Napi::Object m_RaceVehicleData = Napi::Object::New(env);
        m_RaceVehicleData.Set("m_iRaceNum", view->m_RaceVehiclesData[i1].m_iRaceNum);
        m_RaceVehicleData.Set("m_iActive", view->m_RaceVehiclesData[i1].m_iActive);
        m_RaceVehicleData.Set("m_iRPM", view->m_RaceVehiclesData[i1].m_iRPM);
        m_RaceVehicleData.Set("m_iGear", view->m_RaceVehiclesData[i1].m_iGear);
        m_RaceVehicleData.Set("m_fSpeedometer", view->m_RaceVehiclesData[i1].m_fSpeedometer);
        m_RaceVehicleData.Set("m_fSteer", view->m_RaceVehiclesData[i1].m_fSteer);
        m_RaceVehicleData.Set("m_fThrottle", view->m_RaceVehiclesData[i1].m_fThrottle);
        m_RaceVehicleData.Set("m_fBrake", view->m_RaceVehiclesData[i1].m_fBrake);
        m_RaceVehicleData.Freeze();
        m_RaceVehiclesData[i1] = m_RaceVehicleData;
    }

    obj.Set("m_RaceVehiclesData", m_RaceVehiclesData);
    obj.Freeze();

    return obj;
}