//
// Created by Fynn Haupt on 17.06.2023.
//

#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.h"
#include "PluginInfo.h"
#include "PluginInfoWorker.h"

PluginInfoWorker::PluginInfoWorker(Napi::Function &callback, PluginInfo &info)
        : AsyncWorker(callback), info(info) {}

void PluginInfoWorker::Execute() {
    std::string errorMessage = this->info.waitForChange();
    if (errorMessage != "") {
        SetError(errorMessage);
        return;
    }
}

void PluginInfoWorker::OnOK() {
    PluginInfo_t pluginInfo = *this->info.getView();

    Napi::Object obj = Napi::Object::New(Env());
    obj.Set("m_id", pluginInfo.m_id);
    obj.Set("m_iState", pluginInfo.m_iState);
    obj.Set("m_PluginRate", pluginInfo.m_PluginRate);
    obj.Set("m_PluginVersion", pluginInfo.m_PluginVersion);
    obj.Freeze();

    Callback().Call({Env().Null(), obj});
}