import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionType } from "../../enums/RaceSessionType";

export interface SPluginsRaceLap {
    m_iSession: 0 | PractiseSessionType | RaceSessionType;
    m_iSessionSeries: number;
    m_iRaceNum: number;
    m_iLapNum: number;
    m_iInvalid: number;
    m_iLapTime: number;
    m_aiSplit: number[];
    m_fSpeed: number;
    m_iBest: number;
}