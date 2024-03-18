#include "KartLapsInfo.h"

Napi::Value KartLapsInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumLaps", view->_iNumLaps);

    // m_KartLaps
    Napi::Array m_KartLaps = Napi::Array::New(env, view->_iNumLaps);
    for (int i = 0; i < view->_iNumLaps; i++)
    {
        Napi::Object m_KartLap = Napi::Object::New(env);
        m_KartLap.Set("m_iLapNum", view->m_KartLaps[i].m_iLapNum);
        m_KartLap.Set("m_iInvalid", view->m_KartLaps[i].m_iInvalid);
        m_KartLap.Set("m_iLapTime", view->m_KartLaps[i].m_iLapTime);
        m_KartLap.Set("m_iPos", view->m_KartLaps[i].m_iPos);
        m_KartLap.Freeze();
        m_KartLaps[i] = m_KartLap;
    }

    obj.Set("m_KartLaps", m_KartLaps);
    obj.Freeze();

    return obj;
}