#include "KRPSMC.h"

Napi::Value Connect(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    pluginInfo.Connect();

    if (!pluginInfo.connected)
        return Napi::Boolean::New(env, false);

    kartEventInfo.Connect();
    kartSessionInfo.Connect();
    kartTelemetryInfo.Connect();
    kartLapsInfo.Connect();
    kartSplitsInfo.Connect();

    trackSegmentsInfo.Connect();

    raceEventInfo.Connect();
    raceEntriesInfo.Connect();
    raceSessionInfo.Connect();
    raceLapsInfo.Connect();
    raceSplitsInfo.Connect();
    raceSpeedsInfo.Connect();
    raceCommunicationsInfo.Connect();
    raceClassificationInfo.Connect();
    raceTrackPositionsInfo.Connect();
    raceVehiclesDataInfo.Connect();

    camerasInfo.Connect();
    camerasControlInfo.Connect();

    return Napi::Boolean::New(env, true);
}

Napi::Value Disconnect(const Napi::CallbackInfo &info)
{
    pluginInfo.Disconnect();
    kartEventInfo.Disconnect();
    kartSessionInfo.Disconnect();
    kartTelemetryInfo.Disconnect();
    kartLapsInfo.Disconnect();
    kartSplitsInfo.Disconnect();

    trackSegmentsInfo.Disconnect();

    raceEventInfo.Disconnect();
    raceEntriesInfo.Disconnect();
    raceSessionInfo.Disconnect();
    raceLapsInfo.Disconnect();
    raceSplitsInfo.Disconnect();
    raceSpeedsInfo.Disconnect();
    raceCommunicationsInfo.Disconnect();
    raceClassificationInfo.Disconnect();
    raceTrackPositionsInfo.Disconnect();
    raceVehiclesDataInfo.Disconnect();

    camerasInfo.Disconnect();
    camerasControlInfo.Disconnect();

    return info.Env().Undefined();
}

Napi::Value IsConnected(const Napi::CallbackInfo &info)
{
    return Napi::Boolean::New(info.Env(), pluginInfo.connected);
}

Napi::Value GetPluginInfo(const Napi::CallbackInfo &info) {
    return pluginInfo.GetNapiObject(info.Env());
}

Napi::Value GetKartEventInfo(const Napi::CallbackInfo &info) {
    return kartEventInfo.GetNapiObject(info.Env());
}

Napi::Value GetKartSessionInfo(const Napi::CallbackInfo &info) {
    return kartSessionInfo.GetNapiObject(info.Env());
}

Napi::Value GetKartTelemetryInfo(const Napi::CallbackInfo &info) {
    return kartTelemetryInfo.GetNapiObject(info.Env());
}

Napi::Value GetKartLapsInfo(const Napi::CallbackInfo &info) {
    return kartLapsInfo.GetNapiObject(info.Env());
}

Napi::Value GetKartSplitsInfo(const Napi::CallbackInfo &info) {
    return kartSplitsInfo.GetNapiObject(info.Env());
}

Napi::Value GetTrackSegmentsInfo(const Napi::CallbackInfo &info) {
    return trackSegmentsInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceEventInfo(const Napi::CallbackInfo &info) {
    return raceEventInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceEntriesInfo(const Napi::CallbackInfo &info) {
    return raceEntriesInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceSessionInfo(const Napi::CallbackInfo &info) {
    return raceSessionInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceLapsInfo(const Napi::CallbackInfo &info) {
    return raceLapsInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceSplitsInfo(const Napi::CallbackInfo &info) {
    return raceSplitsInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceSpeedsInfo(const Napi::CallbackInfo &info) {
    return raceSpeedsInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceCommunicationsInfo(const Napi::CallbackInfo &info) {
    return raceCommunicationsInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceClassificationInfo(const Napi::CallbackInfo &info) {
    return raceClassificationInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceTrackPositionsInfo(const Napi::CallbackInfo &info) {
    return raceTrackPositionsInfo.GetNapiObject(info.Env());
}

Napi::Value GetRaceVehiclesDataInfo(const Napi::CallbackInfo &info) {
    return raceVehiclesDataInfo.GetNapiObject(info.Env());
}

Napi::Value GetCamerasInfo(const Napi::CallbackInfo &info) {
    return camerasInfo.GetNapiObject(info.Env());
}

Napi::Value SetVehicle(const Napi::CallbackInfo &info)
{
    camerasControlInfo.SetVehicle(info[0].As<Napi::Number>().Int32Value());
    return info.Env().Undefined();
}

Napi::Value SetCamera(const Napi::CallbackInfo &info)
{
    camerasControlInfo.SetCamera(info[0].As<Napi::Number>().Int32Value());
    return info.Env().Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "connect"), Napi::Function::New(env, Connect));
    exports.Set(Napi::String::New(env, "disconnect"), Napi::Function::New(env, Disconnect));
    exports.Set(Napi::String::New(env, "isConnected"), Napi::Function::New(env, IsConnected));
    exports.Set(Napi::String::New(env, "getPluginInfo"), Napi::Function::New(env, GetPluginInfo));
    exports.Set(Napi::String::New(env, "getKartEventInfo"), Napi::Function::New(env, GetKartEventInfo));
    exports.Set(Napi::String::New(env, "getKartSessionInfo"), Napi::Function::New(env, GetKartSessionInfo));
    exports.Set(Napi::String::New(env, "getKartTelemetryInfo"), Napi::Function::New(env, GetKartTelemetryInfo));
    exports.Set(Napi::String::New(env, "getKartLapsInfo"), Napi::Function::New(env, GetKartLapsInfo));
    exports.Set(Napi::String::New(env, "getKartSplitsInfo"), Napi::Function::New(env, GetKartSplitsInfo));
    exports.Set(Napi::String::New(env, "getTrackSegmentsInfo"), Napi::Function::New(env, GetTrackSegmentsInfo));
    exports.Set(Napi::String::New(env, "getRaceEventInfo"), Napi::Function::New(env, GetRaceEventInfo));
    exports.Set(Napi::String::New(env, "getRaceEntriesInfo"), Napi::Function::New(env, GetRaceEntriesInfo));
    exports.Set(Napi::String::New(env, "getRaceSessionInfo"), Napi::Function::New(env, GetRaceSessionInfo));
    exports.Set(Napi::String::New(env, "getRaceLapsInfo"), Napi::Function::New(env, GetRaceLapsInfo));
    exports.Set(Napi::String::New(env, "getRaceSplitsInfo"), Napi::Function::New(env, GetRaceSplitsInfo));
    exports.Set(Napi::String::New(env, "getRaceSpeedsInfo"), Napi::Function::New(env, GetRaceSpeedsInfo));
    exports.Set(Napi::String::New(env, "getRaceCommunicationsInfo"), Napi::Function::New(env, GetRaceCommunicationsInfo));
    exports.Set(Napi::String::New(env, "getRaceClassificationInfo"), Napi::Function::New(env, GetRaceClassificationInfo));
    exports.Set(Napi::String::New(env, "getRaceTrackPositionsInfo"), Napi::Function::New(env, GetRaceTrackPositionsInfo));
    exports.Set(Napi::String::New(env, "getRaceVehiclesDataInfo"), Napi::Function::New(env, GetRaceVehiclesDataInfo));
    exports.Set(Napi::String::New(env, "getCamerasInfo"), Napi::Function::New(env, GetCamerasInfo));
    exports.Set(Napi::String::New(env, "setVehicle"), Napi::Function::New(env, SetVehicle));
    exports.Set(Napi::String::New(env, "setCamera"), Napi::Function::New(env, SetCamera));
    return exports;
}