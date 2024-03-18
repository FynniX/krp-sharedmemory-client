#include "RaceLapsInfo.h"

Napi::Value RaceLapsInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumLaps", view->_iNumLaps);
    
    // m_KartEvent
    Napi::Array m_RaceLaps = Napi::Array::New(env, view->_iNumLaps);
    for (int i1 = 0; i1 < view->_iNumLaps; i1++)
    {
        Napi::Object m_RaceLap = Napi::Object::New(env);
        m_RaceLap.Set("m_iSession", view->m_RaceLaps[i1].m_iSession);
        m_RaceLap.Set("m_iSessionSeries", view->m_RaceLaps[i1].m_iSessionSeries);
        m_RaceLap.Set("m_iRaceNum", view->m_RaceLaps[i1].m_iRaceNum);
        m_RaceLap.Set("m_iLapNum", view->m_RaceLaps[i1].m_iLapNum);
        m_RaceLap.Set("m_iInvalid", view->m_RaceLaps[i1].m_iInvalid);
        m_RaceLap.Set("m_iLapTime", view->m_RaceLaps[i1].m_iLapTime);
        Napi::Array m_aiSplit = Napi::Array::New(env, GetArrayLength(view->m_RaceLaps[i1].m_aiSplit));
        for (int i = 0; i < GetArrayLength(view->m_RaceLaps[i1].m_aiSplit); i++)
            m_aiSplit[i] = view->m_RaceLaps[i1].m_aiSplit[i];
        m_RaceLap.Set("m_aiSplit", m_aiSplit);
        m_RaceLap.Set("m_fSpeed", view->m_RaceLaps[i1].m_fSpeed);
        m_RaceLap.Set("m_iBest", view->m_RaceLaps[i1].m_iBest);
        m_RaceLap.Freeze();
        m_RaceLaps[i1] = m_RaceLap;
    }

    obj.Set("m_RaceLaps", m_RaceLaps);
    obj.Freeze();

    return obj;
}