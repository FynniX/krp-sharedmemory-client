#include "RaceEntriesInfo.h"

Napi::Value RaceEntriesInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumEntries", view->_iNumEntries);
    
    // m_KartEvent
    Napi::Array m_RaceEntries = Napi::Array::New(env, view->_iNumEntries);
    for (int i1 = 0; i1 < view->_iNumEntries; i1++) {
        Napi::Object m_RaceAddEntry = Napi::Object::New(env);
        m_RaceAddEntry.Set("m_iRaceNum", view->m_RaceEntries[i1].m_iRaceNum);
        m_RaceAddEntry.Set("m_szName", GetStringFromChar(view->m_RaceEntries[i1].m_szName));
        m_RaceAddEntry.Set("m_szKartName", GetStringFromChar(view->m_RaceEntries[i1].m_szKartName));
        m_RaceAddEntry.Set("m_szKartShortName", GetStringFromChar(view->m_RaceEntries[i1].m_szKartShortName));
        m_RaceAddEntry.Set("m_szCategory", GetStringFromChar(view->m_RaceEntries[i1].m_szCategory));
        m_RaceAddEntry.Set("m_iUnactive", view->m_RaceEntries[i1].m_iUnactive);
        m_RaceAddEntry.Set("m_iNumberOfGears", view->m_RaceEntries[i1].m_iNumberOfGears);
        m_RaceAddEntry.Set("m_iMaxRPM", view->m_RaceEntries[i1].m_iMaxRPM);
        m_RaceAddEntry.Freeze();
        m_RaceEntries[i1] = m_RaceAddEntry;
    }

    obj.Set("m_RaceEntries", m_RaceEntries);
    obj.Freeze();

    return obj;
}