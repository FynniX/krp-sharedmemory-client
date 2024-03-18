#include "RaceEventInfo.h"

Napi::Value RaceEventInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    
    // m_KartEvent
    Napi::Object m_RaceEvent = Napi::Object::New(env);
    m_RaceEvent.Set("m_iType", view->m_RaceEvent.m_iType);
    m_RaceEvent.Set("m_szName", GetStringFromChar(view->m_RaceEvent.m_szName));
    m_RaceEvent.Set("m_szTrackName", GetStringFromChar(view->m_RaceEvent.m_szTrackName));
    m_RaceEvent.Set("m_fTrackLength", view->m_RaceEvent.m_fTrackLength);
    m_RaceEvent.Freeze();

    obj.Set("m_RaceEvent", m_RaceEvent);
    obj.Freeze();

    return obj;
}