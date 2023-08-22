//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "RaceRemoveEntryInfo.h"
#include "RaceRemoveEntryInfoWorker.h"

RaceRemoveEntryInfoWorker::RaceRemoveEntryInfoWorker(Napi::Function &callback, RaceRemoveEntryInfo &info)
        : AsyncWorker(callback), info(info) {}

void RaceRemoveEntryInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if(errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void RaceRemoveEntryInfoWorker::OnOK() {
    RaceRemoveEntryInfo_t data = *this->info.getView();

    Napi::Object parsed = Napi::Object::New(Env());
parsed.Set("m_id", data.m_id);
Napi::Object m_RaceRemoveEntry = Napi::Object::New(Env());
m_RaceRemoveEntry.Set("m_iRaceNum", data.m_RaceRemoveEntry.m_iRaceNum);
m_RaceRemoveEntry.Freeze();
parsed.Set("m_RaceRemoveEntry", m_RaceRemoveEntry);
parsed.Freeze();

    Callback().Call({Env().Null(), parsed});
}