import type {PluginInfo} from "../types/PluginInfo";
import type {KartEventInfo} from "../types/KartEventInfo";
import type {KartSessionInfo} from "../types/KartSessionInfo";
import type {KartLapInfo} from "../types/KartLapInfo";
import type {KartSplitInfo} from "../types/KartSplitInfo";
import type {KartTelemetryInfo} from "../types/KartTelemetryInfo";
import type {TrackSegmentInfo} from "../types/TrackSegmentInfo";
import type {RaceEventInfo} from "../types/RaceEventInfo";
import type {RaceAddEntryInfo} from "../types/RaceAddEntryInfo";
import type {RaceRemoveEntryInfo} from "../types/RaceRemoveEntryInfo";
import type {RaceSessionInfo} from "../types/RaceSessionInfo";
import type {RaceSessionStateInfo} from "../types/RaceSessionStateInfo";
import type {RaceLapInfo} from "../types/RaceLapInfo";
import type {RaceSplitInfo} from "../types/RaceSplitInfo";
import type {RaceSpeedInfo} from "../types/RaceSpeedInfo";
import type {RaceCommunicationInfo} from "../types/RaceCommunicationInfo";
import type {RaceClassificationInfo} from "../types/RaceClassificationInfo";
import type {RaceTrackPositionInfo} from "../types/RaceTrackPositionInfo";
import type {RaceVehicleDataInfo} from "../types/RaceVehicleDataInfo";
import type {RaceEntriesInfo} from "../types/RaceEntriesInfo";
import { CameraInfo } from "../types/CameraInfo";

export interface WrapperEvents {
  connected: () => void
  disconnected: (reason: string) => void
  pluginInfo: (pluginInfo: PluginInfo) => void
  kartEventInfo: (kartEventInfo: KartEventInfo) => void
  kartSessionInfo: (kartSessionInfo: KartSessionInfo) => void
  kartLapInfo: (kartLapInfo: KartLapInfo) => void
  kartSplitInfo: (kartSplitInfo: KartSplitInfo) => void
  kartTelemetryInfo: (kartTelemetryInfo: KartTelemetryInfo) => void
  trackSegmentInfo: (trackSegmentInfo: TrackSegmentInfo) => void
  raceEventInfo: (raceEventInfo: RaceEventInfo) => void
  raceEntriesInfo: (raceEntriesInfo: RaceEntriesInfo) => void
  raceAddEntryInfo: (raceAddEntryInfo: RaceAddEntryInfo) => void
  raceRemoveEntryInfo: (raceRemoveEntryInfo: RaceRemoveEntryInfo) => void
  raceSessionInfo: (raceSessionInfo: RaceSessionInfo) => void
  raceSessionStateInfo: (raceSessionStateInfo: RaceSessionStateInfo) => void
  raceLapInfo: (raceLapInfo: RaceLapInfo) => void
  raceSplitInfo: (raceSplitInfo: RaceSplitInfo) => void
  raceSpeedInfo: (raceSpeedInfo: RaceSpeedInfo) => void
  raceCommunicationInfo: (raceCommunicationInfo: RaceCommunicationInfo) => void
  raceClassificationInfo: (raceClassificationInfo: RaceClassificationInfo) => void
  raceTrackPositionInfo: (raceTrackPositionInfo: RaceTrackPositionInfo) => void
  raceVehicleDataInfo: (raceVehicleDataInfo: RaceVehicleDataInfo) => void
  cameraInfo: (cameraInfo: CameraInfo) => void
}