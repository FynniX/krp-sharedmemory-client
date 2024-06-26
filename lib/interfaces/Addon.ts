import { KartEventInfo } from "./SharedFileOut/KartEventInfo";
import { KartLapsInfo } from "./SharedFileOut/KartLapsInfo";
import { KartSessionInfo } from "./SharedFileOut/KartSessionInfo";
import { KartSplitsInfo } from "./SharedFileOut/KartSplitsInfo";
import { KartTelemetryInfo } from "./SharedFileOut/KartTelemetryInfo";
import { PluginInfo } from "./SharedFileOut/PluginInfo";
import { RaceEntriesInfo } from "./SharedFileOut/RaceEntriesInfo";
import { RaceEventInfo } from "./SharedFileOut/RaceEventInfo";
import { RaceLapsInfo } from "./SharedFileOut/RaceLapsInfo";
import { RaceSessionInfo } from "./SharedFileOut/RaceSessionInfo";
import { RaceSplitsInfo } from "./SharedFileOut/RaceSplitsInfo";
import { TrackSegmentsInfo } from "./SharedFileOut/TrackSegmentsInfo";
import { RaceSpeedsInfo } from "./SharedFileOut/RaceSpeedsInfo";
import { RaceCommunicationsInfo } from "./SharedFileOut/RaceCommunicationsInfo";
import { RaceClassificationInfo } from "./SharedFileOut/RaceClassificationInfo";
import { RaceTrackPositionsInfo } from "./SharedFileOut/RaceTrackPositionsInfo";
import { RaceVehiclesDataInfo } from "./SharedFileOut/RaceVehiclesDataInfo";
import { CamerasInfo } from "./SharedFileOut/CamerasInfo";

export interface Addon {
  connect(): boolean;
  disconnect(): void;
  isConnected(): boolean;
  getPluginInfo(): PluginInfo;
  getKartEventInfo(): KartEventInfo;
  getKartSessionInfo(): KartSessionInfo;
  getKartTelemetryInfo(): KartTelemetryInfo;
  getKartLapsInfo(): KartLapsInfo;
  getKartSplitsInfo(): KartSplitsInfo;
  getTrackSegmentsInfo(): TrackSegmentsInfo;
  getRaceEventInfo(): RaceEventInfo;
  getRaceEntriesInfo(): RaceEntriesInfo;
  getRaceSessionInfo(): RaceSessionInfo;
  getRaceLapsInfo(): RaceLapsInfo;
  getRaceSplitsInfo(): RaceSplitsInfo;
  getRaceSpeedsInfo(): RaceSpeedsInfo;
  getRaceCommunicationsInfo(): RaceCommunicationsInfo;
  getRaceClassificationInfo(): RaceClassificationInfo;
  getRaceTrackPositionsInfo(): RaceTrackPositionsInfo;
  getRaceVehiclesDataInfo(): RaceVehiclesDataInfo;
  getCamerasInfo(): CamerasInfo;
  setVehicle(vehicle: number): void;
  setCamera(camera: number): void;
}
