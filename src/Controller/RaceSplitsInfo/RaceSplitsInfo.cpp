#include "RaceSplitsInfo.h"

Napi::Value RaceSplitsInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumSplits", view->_iNumSplits);
    
    // m_RaceSplits
    Napi::Array m_RaceSplits = Napi::Array::New(env, view->_iNumSplits);
    for (int i1 = 0; i1 < view->_iNumSplits; i1++)
    {
        Napi::Object m_RaceSplit = Napi::Object::New(env);
        m_RaceSplit.Set("m_iSession", view->m_RaceSplits[i1].m_iSession);
        m_RaceSplit.Set("m_iSessionSeries", view->m_RaceSplits[i1].m_iSessionSeries);
        m_RaceSplit.Set("m_iRaceNum", view->m_RaceSplits[i1].m_iRaceNum);
        m_RaceSplit.Set("m_iLapNum", view->m_RaceSplits[i1].m_iLapNum);
        m_RaceSplit.Set("m_iSplit", view->m_RaceSplits[i1].m_iSplit);
        m_RaceSplit.Set("m_iSplitTime", view->m_RaceSplits[i1].m_iSplitTime);
        m_RaceSplit.Freeze();
        m_RaceSplits[i1] = m_RaceSplit;
    }

    obj.Set("m_RaceSplits", m_RaceSplits);
    obj.Freeze();

    return obj;
}