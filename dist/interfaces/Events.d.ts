import { KartEventInfo } from "./SharedFileOut/KartEventInfo";
import { KartLapsInfo } from "./SharedFileOut/KartLapsInfo";
import { KartSessionInfo } from "./SharedFileOut/KartSessionInfo";
import { KartSplitsInfo } from "./SharedFileOut/KartSplitsInfo";
import { KartTelemetryInfo } from "./SharedFileOut/KartTelemetryInfo";
import { PluginInfo } from "./SharedFileOut/PluginInfo";
import { RaceClassificationInfo } from "./SharedFileOut/RaceClassificationInfo";
import { RaceCommunicationsInfo } from "./SharedFileOut/RaceCommunicationsInfo";
import { RaceEntriesInfo } from "./SharedFileOut/RaceEntriesInfo";
import { RaceEventInfo } from "./SharedFileOut/RaceEventInfo";
import { RaceLapsInfo } from "./SharedFileOut/RaceLapsInfo";
import { RaceSessionInfo } from "./SharedFileOut/RaceSessionInfo";
import { RaceSpeedsInfo } from "./SharedFileOut/RaceSpeedsInfo";
import { RaceSplitsInfo } from "./SharedFileOut/RaceSplitsInfo";
import { RaceTrackPositionsInfo } from "./SharedFileOut/RaceTrackPositionsInfo";
import { RaceVehiclesDataInfo } from "./SharedFileOut/RaceVehiclesDataInfo";
import { TrackSegmentsInfo } from "./SharedFileOut/TrackSegmentsInfo";
import { CamerasInfo } from "./SharedFileOut/CamerasInfo";
export interface Events {
  connected: () => void;
  disconnected: (reason: string) => void;
  pluginInfo: (pluginInfo?: PluginInfo) => void;
  kartEventInfo: (kartEventInfo?: KartEventInfo) => void;
  kartSessionInfo: (kartSessionInfo?: KartSessionInfo) => void;
  kartLapsInfo: (kartLapsInfo?: KartLapsInfo) => void;
  kartSplitsInfo: (kartSplitInfo?: KartSplitsInfo) => void;
  kartTelemetryInfo: (kartTelemetryInfo?: KartTelemetryInfo) => void;
  trackSegmentsInfo: (trackSegmentsInfo?: TrackSegmentsInfo) => void;
  raceEventInfo: (raceEventInfo?: RaceEventInfo) => void;
  raceEntriesInfo: (raceEntriesInfo?: RaceEntriesInfo) => void;
  raceSessionInfo: (raceSessionInfo?: RaceSessionInfo) => void;
  raceLapsInfo: (raceLapInfo?: RaceLapsInfo) => void;
  raceSplitsInfo: (raceSplitInfo?: RaceSplitsInfo) => void;
  raceSpeedsInfo: (raceSpeedsInfo?: RaceSpeedsInfo) => void;
  raceCommunicationsInfo: (
    raceCommunicationsInfo?: RaceCommunicationsInfo,
  ) => void;
  raceClassificationInfo: (
    raceClassificationInfo?: RaceClassificationInfo,
  ) => void;
  raceTrackPositionsInfo: (
    raceTrackPositionsInfo?: RaceTrackPositionsInfo,
  ) => void;
  raceVehiclesDataInfo: (raceVehiclesDataInfo?: RaceVehiclesDataInfo) => void;
  camerasInfo: (camerasInfo?: CamerasInfo) => void;
}
