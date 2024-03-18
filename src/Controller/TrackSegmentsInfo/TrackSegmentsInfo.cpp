#include "TrackSegmentsInfo.h"

Napi::Value TrackSegmentsInfo::GetNapiObject(Napi::Env env)
{
    if (!connected)
        return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("_iNumSegments", view->_iNumSegments);

    // m_TrackSegments
    Napi::Array m_TrackSegments = Napi::Array::New(env, view->_iNumSegments);
    for (int i1 = 0; i1 < view->_iNumSegments; i1++)
    {
        Napi::Object TrackSegment = Napi::Object::New(env);
        TrackSegment.Set("m_iType", view->m_TrackSegments[i1].m_iType);
        TrackSegment.Set("m_fLength", view->m_TrackSegments[i1].m_fLength);
        TrackSegment.Set("m_fRadius", view->m_TrackSegments[i1].m_fRadius);
        TrackSegment.Set("m_fAngle", view->m_TrackSegments[i1].m_fAngle);
        Napi::Array m_afStart = Napi::Array::New(env, GetArrayLength(view->m_TrackSegments[i1].m_afStart));
        for (int i = 0; i < GetArrayLength(view->m_TrackSegments[i1].m_afStart); i++)
            m_afStart[i] = view->m_TrackSegments[i1].m_afStart[i];
        TrackSegment.Set("m_afStart", m_afStart);
        TrackSegment.Set("m_fHeight", view->m_TrackSegments[i1].m_fHeight);
        TrackSegment.Freeze();
        m_TrackSegments[i1] = TrackSegment;
    }
    obj.Set("m_TrackSegments", m_TrackSegments);

    // m_RaceData
    Napi::Array m_RaceData = Napi::Array::New(env, GetArrayLength(view->m_RaceData));
    for (int i = 0; i < GetArrayLength(view->m_RaceData); i++)
        m_RaceData[i] = view->m_RaceData[i];
    obj.Set("m_RaceData", m_RaceData);

    obj.Freeze();

    return obj;
}