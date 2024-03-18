#include "RaceTrackPositionsInfo.h"

Napi::Value RaceTrackPositionsInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumVehicles", view->_iNumVehicles);

    // m_KartEvent
    Napi::Array m_RaceTrackPositions = Napi::Array::New(env, view->_iNumVehicles);
    for (int i1 = 0; i1 < view->_iNumVehicles; i1++)
    {
        Napi::Object RaceTrackPosition = Napi::Object::New(env);
        RaceTrackPosition.Set("m_iRaceNum", view->m_RaceTrackPositions[i1].m_iRaceNum);
        RaceTrackPosition.Set("m_fPosX", view->m_RaceTrackPositions[i1].m_fPosX);
        RaceTrackPosition.Set("m_fPosY", view->m_RaceTrackPositions[i1].m_fPosY);
        RaceTrackPosition.Set("m_fPosZ", view->m_RaceTrackPositions[i1].m_fPosZ);
        RaceTrackPosition.Set("m_fYaw", view->m_RaceTrackPositions[i1].m_fYaw);
        RaceTrackPosition.Set("m_fTrackPos", view->m_RaceTrackPositions[i1].m_fTrackPos);
        RaceTrackPosition.Freeze();
        m_RaceTrackPositions[i1] = RaceTrackPosition;
    }

    obj.Set("m_RaceTrackPositions", m_RaceTrackPositions);
    obj.Freeze();

    return obj;
}