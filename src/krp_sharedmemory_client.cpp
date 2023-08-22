#include <iostream>
#include <napi.h>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "Utils.cpp"
#include "PluginInfo.h"
#include "KartEventInfo.h"
#include "KartSessionInfo.h"
#include "KartLapInfo.h"
#include "KartSplitInfo.h"
#include "KartTelemetryInfo.h"
#include "TrackSegmentInfo.h"
#include "RaceEventInfo.h"
#include "RaceAddEntryInfo.h"
#include "RaceRemoveEntryInfo.h"
#include "RaceSessionInfo.h"
#include "RaceSessionStateInfo.h"
#include "RaceLapInfo.h"
#include "RaceSplitInfo.h"
#include "RaceSpeedInfo.h"
#include "RaceCommunicationInfo.h"
#include "RaceClassificationInfo.h"
#include "RaceTrackPositionInfo.h"
#include "RaceVehicleDataInfo.h"
#include "PluginInfoWorker.h"
#include "KartEventInfoWorker.h"
#include "KartSessionInfoWorker.h"
#include "KartLapInfoWorker.h"
#include "KartSplitInfoWorker.h"
#include "KartTelemetryInfoWorker.h"
#include "TrackSegmentInfoWorker.h"
#include "RaceEventInfoWorker.h"
#include "RaceAddEntryInfoWorker.h"
#include "RaceRemoveEntryInfoWorker.h"
#include "RaceSessionInfoWorker.h"
#include "RaceSessionStateInfoWorker.h"
#include "RaceLapInfoWorker.h"
#include "RaceSplitInfoWorker.h"
#include "RaceSpeedInfoWorker.h"
#include "RaceCommunicationInfoWorker.h"
#include "RaceClassificationInfoWorker.h"
#include "RaceTrackPositionInfoWorker.h"
#include "RaceVehicleDataInfoWorker.h"

using namespace std;

PluginInfo pluginInfo;
KartEventInfo kartEventInfo;
KartSessionInfo kartSessionInfo;
KartLapInfo kartLapInfo;
KartSplitInfo kartSplitInfo;
KartTelemetryInfo kartTelemetryInfo;
TrackSegmentInfo trackSegmentInfo;
RaceEventInfo raceEventInfo;
RaceAddEntryInfo raceAddEntryInfo;
RaceRemoveEntryInfo raceRemoveEntryInfo;
RaceSessionInfo raceSessionInfo;
RaceSessionStateInfo raceSessionStateInfo;
RaceLapInfo raceLapInfo;
RaceSplitInfo raceSplitInfo;
RaceSpeedInfo raceSpeedInfo;
RaceCommunicationInfo raceCommunicationInfo;
RaceClassificationInfo raceClassificationInfo;
RaceTrackPositionInfo raceTrackPositionInfo;
RaceVehicleDataInfo raceVehicleDataInfo;

Napi::Boolean Connect(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();

    pluginInfo.connect();

    if (pluginInfo.isConnected) {
        kartEventInfo.connect();
        kartSessionInfo.connect();
        kartLapInfo.connect();
        kartSplitInfo.connect();
        kartTelemetryInfo.connect();
        trackSegmentInfo.connect();
        raceEventInfo.connect();
        raceAddEntryInfo.connect();
        raceRemoveEntryInfo.connect();
        raceSessionInfo.connect();
        raceSessionStateInfo.connect();
        raceLapInfo.connect();
        raceSplitInfo.connect();
        raceSpeedInfo.connect();
        raceCommunicationInfo.connect();
        raceClassificationInfo.connect();
        raceTrackPositionInfo.connect();
        raceVehicleDataInfo.connect();
    }

    return Napi::Boolean::New(env, pluginInfo.isConnected);
}

Napi::Value Disconnect(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();

    pluginInfo.disconnect();
    kartEventInfo.disconnect();
    kartSessionInfo.disconnect();
    kartLapInfo.disconnect();
    kartSplitInfo.disconnect();
    kartTelemetryInfo.disconnect();
    trackSegmentInfo.disconnect();
    raceEventInfo.disconnect();
    raceAddEntryInfo.disconnect();
    raceRemoveEntryInfo.disconnect();
    raceSessionInfo.disconnect();
    raceSessionStateInfo.disconnect();
    raceLapInfo.disconnect();
    raceSplitInfo.disconnect();
    raceSpeedInfo.disconnect();
    raceCommunicationInfo.disconnect();
    raceClassificationInfo.disconnect();
    raceTrackPositionInfo.disconnect();
    raceVehicleDataInfo.disconnect();

    return env.Null();
}

Napi::Boolean IsConnected(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, pluginInfo.isConnected);
}

Napi::Value SetWaitDelay(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();

    pluginInfo.waitDelay = info[0].ToNumber().Int32Value();
    kartEventInfo.waitDelay = info[0].ToNumber().Int32Value();
    kartSessionInfo.waitDelay = info[0].ToNumber().Int32Value();
    kartLapInfo.waitDelay = info[0].ToNumber().Int32Value();
    kartSplitInfo.waitDelay = info[0].ToNumber().Int32Value();
    kartTelemetryInfo.waitDelay = info[0].ToNumber().Int32Value();
    trackSegmentInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceEventInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceAddEntryInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceRemoveEntryInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceSessionInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceSessionStateInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceLapInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceSplitInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceSpeedInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceCommunicationInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceClassificationInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceTrackPositionInfo.waitDelay = info[0].ToNumber().Int32Value();
    raceVehicleDataInfo.waitDelay = info[0].ToNumber().Int32Value();

    return env.Null();
}

Napi::Value ListenForPluginInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    PluginInfoWorker *worker = new PluginInfoWorker(callback, pluginInfo);
    worker->Queue();
    return env.Null();
}

Napi::Value ListenForKartEventInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    KartEventInfoWorker *worker = new KartEventInfoWorker(callback, kartEventInfo);
    worker->Queue();
    return env.Null();
}

Napi::Value ListenForKartSessionInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    KartSessionInfoWorker *worker = new KartSessionInfoWorker(callback, kartSessionInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForKartLapInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    KartLapInfoWorker *worker = new KartLapInfoWorker(callback, kartLapInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForKartSplitInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    KartSplitInfoWorker *worker = new KartSplitInfoWorker(callback, kartSplitInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForKartTelemetryInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    KartTelemetryInfoWorker *worker = new KartTelemetryInfoWorker(callback, kartTelemetryInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForTrackSegmentInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    TrackSegmentInfoWorker *worker = new TrackSegmentInfoWorker(callback, trackSegmentInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceEventInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceEventInfoWorker *worker = new RaceEventInfoWorker(callback, raceEventInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceAddEntryInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceAddEntryInfoWorker *worker = new RaceAddEntryInfoWorker(callback, raceAddEntryInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceRemoveEntryInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceRemoveEntryInfoWorker *worker = new RaceRemoveEntryInfoWorker(callback, raceRemoveEntryInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceSessionInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceSessionInfoWorker *worker = new RaceSessionInfoWorker(callback, raceSessionInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceSessionStateInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceSessionStateInfoWorker *worker = new RaceSessionStateInfoWorker(callback, raceSessionStateInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceLapInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceLapInfoWorker *worker = new RaceLapInfoWorker(callback, raceLapInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceSplitInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceSplitInfoWorker *worker = new RaceSplitInfoWorker(callback, raceSplitInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceSpeedInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceSpeedInfoWorker *worker = new RaceSpeedInfoWorker(callback, raceSpeedInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceCommunicationInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceCommunicationInfoWorker *worker = new RaceCommunicationInfoWorker(callback, raceCommunicationInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceClassificationInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceClassificationInfoWorker *worker = new RaceClassificationInfoWorker(callback, raceClassificationInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceTrackPositionInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceTrackPositionInfoWorker *worker = new RaceTrackPositionInfoWorker(callback, raceTrackPositionInfo);
    worker->Queue();
    return env.Null();
}


Napi::Value ListenForRaceVehicleDataInfo(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Function callback = info[0].As<Napi::Function>();
    RaceVehicleDataInfoWorker *worker = new RaceVehicleDataInfoWorker(callback, raceVehicleDataInfo);
    worker->Queue();
    return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "connect"), Napi::Function::New(env, Connect));
    exports.Set(Napi::String::New(env, "disconnect"), Napi::Function::New(env, Disconnect));
    exports.Set(Napi::String::New(env, "isConnected"), Napi::Function::New(env, IsConnected));
    exports.Set(Napi::String::New(env, "setWaitDelay"), Napi::Function::New(env, SetWaitDelay));
    exports.Set(Napi::String::New(env, "listenForPluginInfo"), Napi::Function::New(env, ListenForPluginInfo));
    exports.Set(Napi::String::New(env, "listenForKartEventInfo"), Napi::Function::New(env, ListenForKartEventInfo));
    exports.Set(Napi::String::New(env, "listenForKartSessionInfo"), Napi::Function::New(env, ListenForKartSessionInfo));
    exports.Set(Napi::String::New(env, "listenForKartLapInfo"), Napi::Function::New(env, ListenForKartLapInfo));
    exports.Set(Napi::String::New(env, "listenForKartSplitInfo"), Napi::Function::New(env, ListenForKartSplitInfo));
    exports.Set(Napi::String::New(env, "listenForKartTelemetryInfo"),
                Napi::Function::New(env, ListenForKartTelemetryInfo));
    exports.Set(Napi::String::New(env, "listenForTrackSegmentInfo"),
                Napi::Function::New(env, ListenForTrackSegmentInfo));
    exports.Set(Napi::String::New(env, "listenForRaceEventInfo"), Napi::Function::New(env, ListenForRaceEventInfo));
    exports.Set(Napi::String::New(env, "listenForRaceAddEntryInfo"),
                Napi::Function::New(env, ListenForRaceAddEntryInfo));
    exports.Set(Napi::String::New(env, "listenForRaceRemoveEntryInfo"),
                Napi::Function::New(env, ListenForRaceRemoveEntryInfo));
    exports.Set(Napi::String::New(env, "listenForRaceSessionInfo"), Napi::Function::New(env, ListenForRaceSessionInfo));
    exports.Set(Napi::String::New(env, "listenForRaceSessionStateInfo"),
                Napi::Function::New(env, ListenForRaceSessionStateInfo));
    exports.Set(Napi::String::New(env, "listenForRaceLapInfo"), Napi::Function::New(env, ListenForRaceLapInfo));
    exports.Set(Napi::String::New(env, "listenForRaceSplitInfo"), Napi::Function::New(env, ListenForRaceSplitInfo));
    exports.Set(Napi::String::New(env, "listenForRaceSpeedInfo"), Napi::Function::New(env, ListenForRaceSpeedInfo));
    exports.Set(Napi::String::New(env, "listenForRaceCommunicationInfo"),
                Napi::Function::New(env, ListenForRaceCommunicationInfo));
    exports.Set(Napi::String::New(env, "listenForRaceClassificationInfo"),
                Napi::Function::New(env, ListenForRaceClassificationInfo));
    exports.Set(Napi::String::New(env, "listenForRaceTrackPositionInfo"),
                Napi::Function::New(env, ListenForRaceTrackPositionInfo));
    exports.Set(Napi::String::New(env, "listenForRaceVehicleDataInfo"),
                Napi::Function::New(env, ListenForRaceVehicleDataInfo));
    return exports;
}

NODE_API_MODULE(addon, Init)
