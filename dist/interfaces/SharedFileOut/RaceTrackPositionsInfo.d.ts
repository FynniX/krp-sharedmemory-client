import { SPluginsRaceTrackPosition } from "../SharedFileIn/SPluginsRaceTrackPosition";
import { BaseInfo } from "./BaseInfo";
export interface RaceTrackPositionsInfo extends BaseInfo {
    _iNumVehicles: number;
    m_RaceTrackPositions: SPluginsRaceTrackPosition[];
}
