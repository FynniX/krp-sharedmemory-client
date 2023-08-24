//
// Created by Fynn Haupt on 24.08.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceEntriesInfo.h"
#include "RaceEntriesInfoWorker.h"

RaceEntriesInfoWorker::RaceEntriesInfoWorker(Napi::Function &callback, RaceEntriesInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceEntriesInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceEntriesInfoWorker::OnOK() {
    RaceEntriesInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    parsed.Set("_iNumEntries", data._iNumEntries);
    Napi::Array m_RaceEntries = Napi::Array::New(Env(), GetArrayLength(data.m_RaceEntries));
    for (int i1 = 0; i1 < GetArrayLength(data.m_RaceEntries); i1++) {
        Napi::Object m_RaceAddEntry = Napi::Object::New(Env());
        m_RaceAddEntry.Set("m_iRaceNum", data.m_RaceEntries[i1].m_iRaceNum);
        m_RaceAddEntry.Set("m_szName", GetStringFromChar(data.m_RaceEntries[i1].m_szName));
        m_RaceAddEntry.Set("m_szKartName", GetStringFromChar(data.m_RaceEntries[i1].m_szKartName));
        m_RaceAddEntry.Set("m_szKartShortName", GetStringFromChar(data.m_RaceEntries[i1].m_szKartShortName));
        m_RaceAddEntry.Set("m_szCategory", GetStringFromChar(data.m_RaceEntries[i1].m_szCategory));
        m_RaceAddEntry.Set("m_iUnactive", data.m_RaceEntries[i1].m_iUnactive);
        m_RaceAddEntry.Set("m_iNumberOfGears", data.m_RaceEntries[i1].m_iNumberOfGears);
        m_RaceAddEntry.Set("m_iMaxRPM", data.m_RaceEntries[i1].m_iMaxRPM);
        m_RaceAddEntry.Freeze();
        m_RaceEntries[i1] = m_RaceAddEntry;
    }
    parsed.Set("m_RaceEntries", m_RaceEntries);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}
