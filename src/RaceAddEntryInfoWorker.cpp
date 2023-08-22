//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceAddEntryInfo.h"
#include "RaceAddEntryInfoWorker.h"

RaceAddEntryInfoWorker::RaceAddEntryInfoWorker(Napi::Function &callback, RaceAddEntryInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceAddEntryInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceAddEntryInfoWorker::OnOK() {
    RaceAddEntryInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
    parsed.Set("m_id", data.m_id);
    Napi::Object m_RaceAddEntry = Napi::Object::New(Env());
    m_RaceAddEntry.Set("m_iRaceNum", data.m_RaceAddEntry.m_iRaceNum);
    m_RaceAddEntry.Set("m_szName", GetStringFromChar(data.m_RaceAddEntry.m_szName));
    m_RaceAddEntry.Set("m_szKartName", GetStringFromChar(data.m_RaceAddEntry.m_szKartName));
    m_RaceAddEntry.Set("m_szKartShortName", GetStringFromChar(data.m_RaceAddEntry.m_szKartShortName));
    m_RaceAddEntry.Set("m_szCategory", GetStringFromChar(data.m_RaceAddEntry.m_szCategory));
    m_RaceAddEntry.Set("m_iUnactive", data.m_RaceAddEntry.m_iUnactive);
    m_RaceAddEntry.Set("m_iNumberOfGears", data.m_RaceAddEntry.m_iNumberOfGears);
    m_RaceAddEntry.Set("m_iMaxRPM", data.m_RaceAddEntry.m_iMaxRPM);
    m_RaceAddEntry.Freeze();
    parsed.Set("m_RaceAddEntry", m_RaceAddEntry);
    parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}