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

void RaceSplitInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceSplitInfoWorker::OnOK() {
    RaceSplitInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_RaceSplit = Napi::Object::New(Env());
    m_RaceSplit.Set("m_iSession", data.m_RaceSplit.m_iSession);
    m_RaceSplit.Set("m_iSessionSeries", data.m_RaceSplit.m_iSessionSeries);
    m_RaceSplit.Set("m_iRaceNum", data.m_RaceSplit.m_iRaceNum);
    m_RaceSplit.Set("m_iLapNum", data.m_RaceSplit.m_iLapNum);
    m_RaceSplit.Set("m_iSplit", data.m_RaceSplit.m_iSplit);
    m_RaceSplit.Set("m_iSplitTime", data.m_RaceSplit.m_iSplitTime);
    m_RaceSplit.Freeze();
    parsed.Set("m_RaceSplit", m_RaceSplit);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}