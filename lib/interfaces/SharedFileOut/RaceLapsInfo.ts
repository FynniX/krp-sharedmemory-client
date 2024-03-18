import { SPluginsRaceLap } from "../SharedFileIn/SPluginsRaceLap";
import { BaseInfo } from "./BaseInfo";

export interface RaceLapsInfo extends BaseInfo {
    _iNumLaps: number;
    m_RaceLaps: SPluginsRaceLap[];
}