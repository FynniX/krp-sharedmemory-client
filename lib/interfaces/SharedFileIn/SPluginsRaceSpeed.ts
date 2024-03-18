import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionType } from "../../enums/RaceSessionType";

export interface SPluginsRaceSpeed {
    m_iSession: 0 | PractiseSessionType | RaceSessionType;
    m_iSessionSeries: number;
    m_iRaceNum: number;
    m_iLapNum: number;
    m_fSpeed: number;
}