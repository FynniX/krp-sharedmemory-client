#include "RaceSessionInfo.h"

Napi::Value RaceSessionInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    
    // m_RaceSession
    Napi::Object m_RaceSession = Napi::Object::New(env);
    m_RaceSession.Set("m_iSession", view->m_RaceSession.m_iSession);
    m_RaceSession.Set("m_iSessionSeries", view->m_RaceSession.m_iSessionSeries);
    m_RaceSession.Set("m_iGroup1", view->m_RaceSession.m_iGroup1);
    m_RaceSession.Set("m_iGroup2", view->m_RaceSession.m_iGroup2);
    m_RaceSession.Set("m_iSessionState", view->m_RaceSession.m_iSessionState);
    m_RaceSession.Set("m_iSessionLength", view->m_RaceSession.m_iSessionLength);
    m_RaceSession.Set("m_iSessionNumLaps", view->m_RaceSession.m_iSessionNumLaps);
    m_RaceSession.Set("m_iNumEntries", view->m_RaceSession.m_iNumEntries);
    Napi::Array m_aiEntries = Napi::Array::New(env, GetArrayLength(view->m_RaceSession.m_aiEntries));
    for (int i = 0; i < GetArrayLength(view->m_RaceSession.m_aiEntries); i++)
        m_aiEntries[i] = view->m_RaceSession.m_aiEntries[i];
    m_RaceSession.Set("m_aiEntries", m_aiEntries);
    Napi::Array m_aiGrid = Napi::Array::New(env, GetArrayLength(view->m_RaceSession.m_aiGrid));
    for (int i = 0; i < GetArrayLength(view->m_RaceSession.m_aiGrid); i++)
        m_aiGrid[i] = view->m_RaceSession.m_aiGrid[i];
    m_RaceSession.Set("m_aiGrid", m_aiGrid);
    m_RaceSession.Set("m_iConditions", view->m_RaceSession.m_iConditions);
    m_RaceSession.Set("m_fAirTemperature", view->m_RaceSession.m_fAirTemperature);
    m_RaceSession.Set("m_fTrackTemperature", view->m_RaceSession.m_fTrackTemperature);
    m_RaceSession.Freeze();

    obj.Set("m_RaceSession", m_RaceSession);
    obj.Freeze();

    return obj;
}