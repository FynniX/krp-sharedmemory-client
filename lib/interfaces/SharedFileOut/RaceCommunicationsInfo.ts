import { SPluginsRaceCommunication } from "../SharedFileIn/SPluginsRaceCommunication";
import { BaseInfo } from "./BaseInfo";

export interface RaceCommunicationsInfo extends BaseInfo {
    _iNumCommunications: number;
    m_RaceCommunications: SPluginsRaceCommunication[];
}