import type {PluginInfo} from "./types/PluginInfo";
import type {KartEventInfo} from "./types/KartEventInfo";
import type {KartSessionInfo} from "./types/KartSessionInfo";
import type {KartLapInfo} from "./types/KartLapInfo";
import type {KartSplitInfo} from "./types/KartSplitInfo";
import type {KartTelemetryInfo} from "./types/KartTelemetryInfo";
import type {TrackSegmentInfo} from "./types/TrackSegmentInfo";
import type {RaceEventInfo} from "./types/RaceEventInfo";
import type {RaceAddEntryInfo} from "./types/RaceAddEntryInfo";
import type {RaceRemoveEntryInfo} from "./types/RaceRemoveEntryInfo";
import type {RaceSessionInfo} from "./types/RaceSessionInfo";
import type {RaceSessionStateInfo} from "./types/RaceSessionStateInfo";
import type {RaceLapInfo} from "./types/RaceLapInfo";
import type {RaceSplitInfo} from "./types/RaceSplitInfo";
import type {RaceSpeedInfo} from "./types/RaceSpeedInfo";
import type {RaceCommunicationInfo} from "./types/RaceCommunicationInfo";
import type {RaceClassificationInfo} from "./types/RaceClassificationInfo";
import type {RaceTrackPositionInfo} from "./types/RaceTrackPositionInfo";
import type {RaceVehicleDataInfo} from "./types/RaceVehicleDataInfo";
import type {RaceEntriesInfo} from "./types/RaceEntriesInfo";

type Addon = {
  connect(): boolean,
  disconnect(): null,
  isConnected(): boolean,
  setWaitDelay(waitDelay: number): null,
  listenForPluginInfo(cb: (err: Error, data: PluginInfo) => void): null
  listenForKartEventInfo(cb: (err: Error, data: KartEventInfo) => void): null
  listenForKartSessionInfo(cb: (err: Error, data: KartSessionInfo) => void): null
  listenForKartLapInfo(cb: (err: Error, data: KartLapInfo) => void): null
  listenForKartSplitInfo(cb: (err: Error, data: KartSplitInfo) => void): null
  listenForKartTelemetryInfo(cb: (err: Error, data: KartTelemetryInfo) => void): null
  listenForTrackSegmentInfo(cb: (err: Error, data: TrackSegmentInfo) => void): null
  listenForRaceEventInfo(cb: (err: Error, data: RaceEventInfo) => void): null
  listenForRaceEntriesInfo(cb: (err: Error, data: RaceEntriesInfo) => void): null
  listenForRaceAddEntryInfo(cb: (err: Error, data: RaceAddEntryInfo) => void): null
  listenForRaceRemoveEntryInfo(cb: (err: Error, data: RaceRemoveEntryInfo) => void): null
  listenForRaceSessionInfo(cb: (err: Error, data: RaceSessionInfo) => void): null
  listenForRaceSessionStateInfo(cb: (err: Error, data: RaceSessionStateInfo) => void): null
  listenForRaceLapInfo(cb: (err: Error, data: RaceLapInfo) => void): null
  listenForRaceSplitInfo(cb: (err: Error, data: RaceSplitInfo) => void): null
  listenForRaceSpeedInfo(cb: (err: Error, data: RaceSpeedInfo) => void): null
  listenForRaceCommunicationInfo(cb: (err: Error, data: RaceCommunicationInfo) => void): null
  listenForRaceClassificationInfo(cb: (err: Error, data: RaceClassificationInfo) => void): null
  listenForRaceTrackPositionInfo(cb: (err: Error, data: RaceTrackPositionInfo) => void): null
  listenForRaceVehicleDataInfo(cb: (err: Error, data: RaceVehicleDataInfo) => void): null
}

const addon: Addon = require('../build/Release/krp-sharedmemory-client-native');

async function listenForPluginInfoPromise(): Promise<PluginInfo> {
  return new Promise<PluginInfo>((resolve, reject) => {
    addon.listenForPluginInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}

async function listenForKartEventInfoPromise(): Promise<KartEventInfo> {
  return new Promise<KartEventInfo>((resolve, reject) => {
    addon.listenForKartEventInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForKartSessionInfoPromise(): Promise<KartSessionInfo> {
  return new Promise<KartSessionInfo>((resolve, reject) => {
    addon.listenForKartSessionInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForKartLapInfoPromise(): Promise<KartLapInfo> {
  return new Promise<KartLapInfo>((resolve, reject) => {
    addon.listenForKartLapInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForKartSplitInfoPromise(): Promise<KartSplitInfo> {
  return new Promise<KartSplitInfo>((resolve, reject) => {
    addon.listenForKartSplitInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForKartTelemetryInfoPromise(): Promise<KartTelemetryInfo> {
  return new Promise<KartTelemetryInfo>((resolve, reject) => {
    addon.listenForKartTelemetryInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForTrackSegmentInfoPromise(): Promise<TrackSegmentInfo> {
  return new Promise<TrackSegmentInfo>((resolve, reject) => {
    addon.listenForTrackSegmentInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceEventInfoPromise(): Promise<RaceEventInfo> {
  return new Promise<RaceEventInfo>((resolve, reject) => {
    addon.listenForRaceEventInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceEntriesInfoPromise(): Promise<RaceEntriesInfo> {
  return new Promise<RaceEntriesInfo>((resolve, reject) => {
    addon.listenForRaceEntriesInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceAddEntryInfoPromise(): Promise<RaceAddEntryInfo> {
  return new Promise<RaceAddEntryInfo>((resolve, reject) => {
    addon.listenForRaceAddEntryInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceRemoveEntryInfoPromise(): Promise<RaceRemoveEntryInfo> {
  return new Promise<RaceRemoveEntryInfo>((resolve, reject) => {
    addon.listenForRaceRemoveEntryInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceSessionInfoPromise(): Promise<RaceSessionInfo> {
  return new Promise<RaceSessionInfo>((resolve, reject) => {
    addon.listenForRaceSessionInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceSessionStateInfoPromise(): Promise<RaceSessionStateInfo> {
  return new Promise<RaceSessionStateInfo>((resolve, reject) => {
    addon.listenForRaceSessionStateInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceLapInfoPromise(): Promise<RaceLapInfo> {
  return new Promise<RaceLapInfo>((resolve, reject) => {
    addon.listenForRaceLapInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceSplitInfoPromise(): Promise<RaceSplitInfo> {
  return new Promise<RaceSplitInfo>((resolve, reject) => {
    addon.listenForRaceSplitInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceSpeedInfoPromise(): Promise<RaceSpeedInfo> {
  return new Promise<RaceSpeedInfo>((resolve, reject) => {
    addon.listenForRaceSpeedInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceCommunicationInfoPromise(): Promise<RaceCommunicationInfo> {
  return new Promise<RaceCommunicationInfo>((resolve, reject) => {
    addon.listenForRaceCommunicationInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceClassificationInfoPromise(): Promise<RaceClassificationInfo> {
  return new Promise<RaceClassificationInfo>((resolve, reject) => {
    addon.listenForRaceClassificationInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceTrackPositionInfoPromise(): Promise<RaceTrackPositionInfo> {
  return new Promise<RaceTrackPositionInfo>((resolve, reject) => {
    addon.listenForRaceTrackPositionInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}


async function listenForRaceVehicleDataInfoPromise(): Promise<RaceVehicleDataInfo> {
  return new Promise<RaceVehicleDataInfo>((resolve, reject) => {
    addon.listenForRaceVehicleDataInfo((err, data) => {
      if (err) return reject(err);
      resolve(data);
    })
  });
}

export = {
  ...addon,
  listenForPluginInfoPromise,
  listenForKartEventInfoPromise,
  listenForKartSessionInfoPromise,
  listenForKartLapInfoPromise,
  listenForKartSplitInfoPromise,
  listenForKartTelemetryInfoPromise,
  listenForTrackSegmentInfoPromise,
  listenForRaceEventInfoPromise,
  listenForRaceEntriesInfoPromise,
  listenForRaceAddEntryInfoPromise,
  listenForRaceRemoveEntryInfoPromise,
  listenForRaceSessionInfoPromise,
  listenForRaceSessionStateInfoPromise,
  listenForRaceLapInfoPromise,
  listenForRaceSplitInfoPromise,
  listenForRaceSpeedInfoPromise,
  listenForRaceCommunicationInfoPromise,
  listenForRaceClassificationInfoPromise,
  listenForRaceTrackPositionInfoPromise,
  listenForRaceVehicleDataInfoPromise
}

