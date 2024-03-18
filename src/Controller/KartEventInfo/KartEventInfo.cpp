#include "KartEventInfo.h"

Napi::Value KartEventInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    
    // m_KartEvent
    Napi::Object m_KartEvent = Napi::Object::New(env);
    m_KartEvent.Set("m_szDriverName", GetStringFromChar(view->m_KartEvent.m_szDriverName));
    m_KartEvent.Set("m_szKartID", GetStringFromChar(view->m_KartEvent.m_szKartID));
    m_KartEvent.Set("m_szKartName", GetStringFromChar(view->m_KartEvent.m_szKartName));
    m_KartEvent.Set("m_iDriveType", view->m_KartEvent.m_iDriveType);
    m_KartEvent.Set("m_iNumberOfGears", view->m_KartEvent.m_iNumberOfGears);
    m_KartEvent.Set("m_iMaxRPM", view->m_KartEvent.m_iMaxRPM);
    m_KartEvent.Set("m_iLimiter", view->m_KartEvent.m_iLimiter);
    m_KartEvent.Set("m_iShiftRPM", view->m_KartEvent.m_iShiftRPM);
    m_KartEvent.Set("m_iEngineCooling", view->m_KartEvent.m_iEngineCooling);
    m_KartEvent.Set("m_fEngineOptTemperature", view->m_KartEvent.m_fEngineOptTemperature);
    Napi::Array m_afEngineTemperatureAlarm = Napi::Array::New(env, GetArrayLength(view->m_KartEvent.m_afEngineTemperatureAlarm));
    for (int i = 0; i < GetArrayLength(view->m_KartEvent.m_afEngineTemperatureAlarm); i++)
        m_afEngineTemperatureAlarm[i] = view->m_KartEvent.m_afEngineTemperatureAlarm[i];
    m_KartEvent.Set("m_afEngineTemperatureAlarm", m_afEngineTemperatureAlarm);
    m_KartEvent.Set("m_fMaxFuel", view->m_KartEvent.m_fMaxFuel);
    m_KartEvent.Set("m_szCategory", GetStringFromChar(view->m_KartEvent.m_szCategory));
    m_KartEvent.Set("m_szDash", GetStringFromChar(view->m_KartEvent.m_szDash));
    m_KartEvent.Set("m_szTrackID", GetStringFromChar(view->m_KartEvent.m_szTrackID));
    m_KartEvent.Set("m_szTrackName", GetStringFromChar(view->m_KartEvent.m_szTrackName));
    m_KartEvent.Set("m_fTrackLength", view->m_KartEvent.m_fTrackLength);
    m_KartEvent.Set("m_iType", view->m_KartEvent.m_iType);
    m_KartEvent.Freeze();

    obj.Set("m_KartEvent", m_KartEvent);
    obj.Freeze();

    return obj;
}