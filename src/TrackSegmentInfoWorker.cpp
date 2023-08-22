//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "TrackSegmentInfo.h"
#include "TrackSegmentInfoWorker.h"

TrackSegmentInfoWorker::TrackSegmentInfoWorker(Napi::Function &callback, TrackSegmentInfo &info)
        : AsyncWorker(callback), info(info) {}

void TrackSegmentInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void TrackSegmentInfoWorker::OnOK() {
    TrackSegmentInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    parsed.Set("_iNumSegments", data._iNumSegments);
    Napi::Array m_TrackSegments = Napi::Array::New(Env(), GetArrayLength(data.m_TrackSegments));
    for (int i1 = 0; i1 < GetArrayLength(data.m_TrackSegments); i1++) {
        Napi::Object obj = Napi::Object::New(Env());
        obj.Set("m_iType", data.m_TrackSegments[i1].m_iType);
        obj.Set("m_fLength", data.m_TrackSegments[i1].m_fLength);
        obj.Set("m_fRadius", data.m_TrackSegments[i1].m_fRadius);
        obj.Set("m_fAngle", data.m_TrackSegments[i1].m_fAngle);
        Napi::Array m_afStart = Napi::Array::New(Env(), GetArrayLength(data.m_TrackSegments[i1].m_afStart));
        for (int i = 0; i < GetArrayLength(data.m_TrackSegments[i1].m_afStart); i++)
            m_afStart[i] = data.m_TrackSegments[i1].m_afStart[i];
        obj.Set("m_afStart", m_afStart);
        obj.Set("m_fHeight", data.m_TrackSegments[i1].m_fHeight);
        obj.Freeze();
        m_TrackSegments[i1] = obj;
    }
    parsed.Set("m_TrackSegments", m_TrackSegments);
    Napi::Array m_RaceData = Napi::Array::New(Env(), GetArrayLength(data.m_RaceData));
    for (int i = 0; i < GetArrayLength(data.m_RaceData); i++)
        m_RaceData[i] = data.m_RaceData[i];
    parsed.Set("m_RaceData", m_RaceData);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}