#include "RaceClassificationInfo.h"

Napi::Value RaceClassificationInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);

    // m_RaceClassification
    Napi::Object m_RaceClassification = Napi::Object::New(env);
    m_RaceClassification.Set("m_iSession", view->m_RaceClassification.m_iSession);
    m_RaceClassification.Set("m_iSessionSeries", view->m_RaceClassification.m_iSessionSeries);
    m_RaceClassification.Set("m_iSessionState", view->m_RaceClassification.m_iSessionState);
    m_RaceClassification.Set("m_iSessionTime", view->m_RaceClassification.m_iSessionTime);
    m_RaceClassification.Set("m_iNumEntries", view->m_RaceClassification.m_iNumEntries);
    m_RaceClassification.Freeze();

    obj.Set("m_RaceClassification", m_RaceClassification);

    // m_RaceClassificationEntries
    Napi::Array m_RaceClassificationEntries = Napi::Array::New(env, view->m_RaceClassification.m_iNumEntries);
    for (int i1 = 0; i1 < view->m_RaceClassification.m_iNumEntries; i1++)
    {
        Napi::Object RaceClassificationEntry = Napi::Object::New(env);
        RaceClassificationEntry.Set("m_iRaceNum", view->m_RaceClassificationEntries[i1].m_iRaceNum);
        RaceClassificationEntry.Set("m_iState", view->m_RaceClassificationEntries[i1].m_iState);
        RaceClassificationEntry.Set("m_iBestLap", view->m_RaceClassificationEntries[i1].m_iBestLap);
        RaceClassificationEntry.Set("m_fBestSpeed", view->m_RaceClassificationEntries[i1].m_fBestSpeed);
        RaceClassificationEntry.Set("m_iBestLapNum", view->m_RaceClassificationEntries[i1].m_iBestLapNum);
        RaceClassificationEntry.Set("m_iNumLaps", view->m_RaceClassificationEntries[i1].m_iNumLaps);
        RaceClassificationEntry.Set("m_iGap", view->m_RaceClassificationEntries[i1].m_iGap);
        RaceClassificationEntry.Set("m_iGapLaps", view->m_RaceClassificationEntries[i1].m_iGapLaps);
        RaceClassificationEntry.Set("m_iPenalty", view->m_RaceClassificationEntries[i1].m_iPenalty);
        RaceClassificationEntry.Set("m_iPit", view->m_RaceClassificationEntries[i1].m_iPit);
        RaceClassificationEntry.Freeze();
        m_RaceClassificationEntries[i1] = RaceClassificationEntry;
    }

    obj.Set("m_RaceClassificationEntries", m_RaceClassificationEntries);
    obj.Freeze();

    return obj;
}