#include "KartSessionInfo.h"

Napi::Value KartSessionInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    
    // m_KartSession
    Napi::Object m_KartSession = Napi::Object::New(env);
    m_KartSession.Set("m_iSession", view->m_KartSession.m_iSession);
    m_KartSession.Set("m_iSessionSeries", view->m_KartSession.m_iSessionSeries);
    m_KartSession.Set("m_iConditions", view->m_KartSession.m_iConditions);
    m_KartSession.Set("m_fAirTemperature", view->m_KartSession.m_fAirTemperature);
    m_KartSession.Set("m_fTrackTemperature", view->m_KartSession.m_fTrackTemperature);
    m_KartSession.Set("m_szSetupFileName", GetStringFromChar(view->m_KartSession.m_szSetupFileName));
    m_KartSession.Freeze();

    obj.Set("m_KartSession", m_KartSession);
    obj.Freeze();

    return obj;
}