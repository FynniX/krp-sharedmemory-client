#include "RaceCommunicationsInfo.h"

Napi::Value RaceCommunicationsInfo::GetNapiObject(Napi::Env env)
{
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumCommunications", view->_iNumCommunications);
    
    // m_KartEvent
    Napi::Array m_RaceCommunications = Napi::Array::New(env, view->_iNumCommunications);
    for (int i1 = 0; i1 < view->_iNumCommunications; i1++)
    {
        Napi::Object m_RaceCommunication = Napi::Object::New(env);
        m_RaceCommunication.Set("m_iSession", view->m_RaceCommunications[i1].m_iSession);
        m_RaceCommunication.Set("m_iSessionSeries", view->m_RaceCommunications[i1].m_iSessionSeries);
        m_RaceCommunication.Set("m_iRaceNum", view->m_RaceCommunications[i1].m_iRaceNum);
        m_RaceCommunication.Set("m_iCommunication", view->m_RaceCommunications[i1].m_iCommunication);
        m_RaceCommunication.Set("m_iState", view->m_RaceCommunications[i1].m_iState);
        m_RaceCommunication.Set("m_iReason", view->m_RaceCommunications[i1].m_iReason);
        m_RaceCommunication.Set("m_iOffence", view->m_RaceCommunications[i1].m_iOffence);
        m_RaceCommunication.Set("m_iLap", view->m_RaceCommunications[i1].m_iLap);
        m_RaceCommunication.Set("m_iType", view->m_RaceCommunications[i1].m_iType);
        m_RaceCommunication.Set("m_iTime", view->m_RaceCommunications[i1].m_iTime);
        m_RaceCommunication.Freeze();
        m_RaceCommunications[i1] = m_RaceCommunication;
    }

    obj.Set("m_RaceCommunications", m_RaceCommunications);
    obj.Freeze();

    return obj;
}