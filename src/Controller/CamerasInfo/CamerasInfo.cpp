#include "CamerasInfo.h"

Napi::Value CamerasInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("currentVehicle", view->currentVehicle);
    obj.Set("currentCamera", view->currentCamera);
    obj.Set("_iNumVehicles", view->_iNumVehicles);
    obj.Set("_iNumCameras", view->_iNumCameras);

    Napi::Array m_Vehicles = Napi::Array::New(env, view->_iNumVehicles);
    for (int i = 0; i < view->_iNumVehicles; i++)
    {
        Napi::Object m_Vehicle = Napi::Object::New(env);
        m_Vehicle.Set("m_iRaceNum", view->m_Vehicles[i].m_iRaceNum);
        m_Vehicle.Set("m_szName", GetStringFromChar(view->m_Vehicles[i].m_szName));
        m_Vehicle.Freeze();
        m_Vehicles[i] = m_Vehicle;
    }

    Napi::Array m_CameraNames = Napi::Array::New(env, view->_iNumCameras);
    for (int i = 0; i < view->_iNumCameras; i++)
        m_CameraNames[i] = GetStringFromChar(view->m_CameraNames[i]);

    obj.Set("m_Vehicles", m_Vehicles);
    obj.Set("m_CameraNames", m_CameraNames);
    obj.Freeze();

    return obj;
}