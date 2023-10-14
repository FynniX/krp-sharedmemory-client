//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceSplitInfo.h"
#include "RaceSplitInfoWorker.h"

RaceSplitInfoWorker::RaceSplitInfoWorker(Napi::Function &callback, RaceSplitInfo &info)
    : AsyncWorker(callback), info(info) {}

void RaceSplitInfoWorker::Execute()
{
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "")
    {
        SetError(errorMessage);
        return;
    }
}

void RaceSplitInfoWorker::OnOK()
{
    RaceSplitInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);

    Napi::Array m_RaceSplits = Napi::Array::New(Env(), GetArrayLength(data.m_RaceSplits));
    for (int i1 = 0; i1 < GetArrayLength(data.m_RaceSplits); i1++)
    {
        Napi::Object m_RaceSplit = Napi::Object::New(Env());
        m_RaceSplit.Set("m_iSession", data.m_RaceSplits[i1].m_iSession);
        m_RaceSplit.Set("m_iSessionSeries", data.m_RaceSplits[i1].m_iSessionSeries);
        m_RaceSplit.Set("m_iRaceNum", data.m_RaceSplits[i1].m_iRaceNum);
        m_RaceSplit.Set("m_iLapNum", data.m_RaceSplits[i1].m_iLapNum);
        m_RaceSplit.Set("m_iSplit", data.m_RaceSplits[i1].m_iSplit);
        m_RaceSplit.Set("m_iSplitTime", data.m_RaceSplits[i1].m_iSplitTime);
        m_RaceSplit.Freeze();
        m_RaceSplits[i1] = m_RaceSplit;
    }
    parsed.Set("m_RaceSplits", m_RaceSplits);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}