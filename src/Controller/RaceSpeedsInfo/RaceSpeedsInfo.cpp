#include "RaceSpeedsInfo.h"

Napi::Value RaceSpeedsInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    
    // m_RaceSpeeds
    Napi::Array m_RaceSpeeds = Napi::Array::New(env, GetArrayLength(view->m_RaceSpeeds));
    for (int i1 = 0; i1 < GetArrayLength(view->m_RaceSpeeds); i1++)
    {
        Napi::Object m_RaceSpeed = Napi::Object::New(env);
        m_RaceSpeed.Set("m_iSession", view->m_RaceSpeeds[i1].m_iSession);
        m_RaceSpeed.Set("m_iSessionSeries", view->m_RaceSpeeds[i1].m_iSessionSeries);
        m_RaceSpeed.Set("m_iRaceNum", view->m_RaceSpeeds[i1].m_iRaceNum);
        m_RaceSpeed.Set("m_iLapNum", view->m_RaceSpeeds[i1].m_iLapNum);
        m_RaceSpeed.Set("m_fSpeed", view->m_RaceSpeeds[i1].m_fSpeed);
        m_RaceSpeed.Freeze();
        m_RaceSpeeds[i1] = m_RaceSpeed;
    }

    obj.Set("m_RaceSpeeds", m_RaceSpeeds);
    obj.Freeze();

    return obj;
}