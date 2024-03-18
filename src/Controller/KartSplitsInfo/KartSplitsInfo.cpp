#include "KartSplitsInfo.h"

Napi::Value KartSplitsInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumSplits", view->_iNumSplits);

    // m_KartSplits
    Napi::Array m_KartSplits = Napi::Array::New(env, view->_iNumSplits);
    for(int i = 0; i < view->_iNumSplits; i++)
    {
        Napi::Object m_KartSplit = Napi::Object::New(env);
        m_KartSplit.Set("m_iSplit", view->m_KartSplits[i].m_iSplit);
        m_KartSplit.Set("m_iSplitTime", view->m_KartSplits[i].m_iSplitTime);
        m_KartSplit.Set("m_iBestDiff", view->m_KartSplits[i].m_iBestDiff);
        m_KartSplit.Freeze();
        m_KartSplits[i] = m_KartSplit;
    }

    obj.Set("m_KartSplits", m_KartSplits);
    obj.Freeze();

    return obj;
}