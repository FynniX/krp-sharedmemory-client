import { EntryPosition } from "../../enums/EntryPosition";
import { EntryState } from "../../enums/EntryState";

export interface SPluginsRaceClassificationEntry {
    m_iRaceNum: number;
    m_iState: EntryState;
    m_iBestLap: number;
    m_fBestSpeed: number;
    m_iBestLapNum: number;
    m_iNumLaps: number;
    m_iGap: number;
    m_iGapLaps: number;
    m_iPenalty: number;
    m_iPit: EntryPosition;
}