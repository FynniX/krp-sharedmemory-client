#ifndef KRPSMC_H
#define KRPSMC_H

#include <iostream>
#include <string>
#include <napi.h>
#include "Controller/PluginInfo/PluginInfo.h"
#include "Controller/KartEventInfo/KartEventInfo.h"
#include "Controller/KartSessionInfo/KartSessionInfo.h"
#include "Controller/KartTelemetryInfo/KartTelemetryInfo.h"
#include "Controller/KartLapsInfo/KartLapsInfo.h"
#include "Controller/KartSplitsInfo/KartSplitsInfo.h"
#include "Controller/TrackSegmentsInfo/TrackSegmentsInfo.h"
#include "Controller/RaceEventInfo/RaceEventInfo.h"
#include "Controller/RaceEntriesInfo/RaceEntriesInfo.h"
#include "Controller/RaceSessionInfo/RaceSessionInfo.h"
#include "Controller/RaceLapsInfo/RaceLapsInfo.h"
#include "Controller/RaceSplitsInfo/RaceSplitsInfo.h"
#include "Controller/RaceSpeedsInfo/RaceSpeedsInfo.h"
#include "Controller/RaceCommunicationsInfo/RaceCommunicationsInfo.h"
#include "Controller/RaceClassificationInfo/RaceClassificationInfo.h"
#include "Controller/RaceTrackPositionsInfo/RaceTrackPositionsInfo.h"
#include "Controller/RaceVehiclesDataInfo/RaceVehiclesDataInfo.h"
#include "Controller/CamerasInfo/CamerasInfo.h"
#include "Controller/CamerasControlInfo/CamerasControlInfo.h"

PluginInfo pluginInfo;
KartEventInfo kartEventInfo;
KartSessionInfo kartSessionInfo;
KartTelemetryInfo kartTelemetryInfo;
KartLapsInfo kartLapsInfo;
KartSplitsInfo kartSplitsInfo;
TrackSegmentsInfo trackSegmentsInfo;
RaceEventInfo raceEventInfo;
RaceEntriesInfo raceEntriesInfo;
RaceSessionInfo raceSessionInfo;
RaceLapsInfo raceLapsInfo;
RaceSplitsInfo raceSplitsInfo;
RaceSpeedsInfo raceSpeedsInfo;
RaceCommunicationsInfo raceCommunicationsInfo;
RaceClassificationInfo raceClassificationInfo;
RaceTrackPositionsInfo raceTrackPositionsInfo;
RaceVehiclesDataInfo raceVehiclesDataInfo;
CamerasInfo camerasInfo;
CamerasControlInfo camerasControlInfo;

Napi::Value Connect(const Napi::CallbackInfo &info);
Napi::Value Disconnect(const Napi::CallbackInfo &info);
Napi::Value IsConnected(const Napi::CallbackInfo &info);

Napi::Object Init(Napi::Env env, Napi::Object exports);

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

#endif