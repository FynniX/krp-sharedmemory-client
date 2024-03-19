import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionType } from "../../enums/RaceSessionType";
export interface SPluginsRaceSplit {
    m_iSession: 0 | PractiseSessionType | RaceSessionType;
    m_iSessionSeries: number;
    m_iRaceNum: number;
    m_iLapNum: number;
    m_iSplit: number;
    m_iSplitTime: number;
}
