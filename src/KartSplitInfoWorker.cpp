//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "KartSplitInfo.h"
#include "KartSplitInfoWorker.h"

KartSplitInfoWorker::KartSplitInfoWorker(Napi::Function &callback, KartSplitInfo &info)
        : AsyncWorker(callback), info(info) {}

void KartSplitInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void KartSplitInfoWorker::OnOK() {
    KartSplitInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_KartSplit = Napi::Object::New(Env());
    m_KartSplit.Set("m_iSplit", data.m_KartSplit.m_iSplit);
    m_KartSplit.Set("m_iSplitTime", data.m_KartSplit.m_iSplitTime);
    m_KartSplit.Set("m_iBestDiff", data.m_KartSplit.m_iBestDiff);
    m_KartSplit.Freeze();
    parsed.Set("m_KartSplit", m_KartSplit);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}