import { SPluginsKartLap } from "../SharedFileIn/SPluginsKartLap";
import { BaseInfo } from "./BaseInfo";
export interface KartLapsInfo extends BaseInfo {
    _iNumLaps: number;
    m_KartLaps: SPluginsKartLap[];
}
