import { PractiseSessionState } from "../../enums/PractiseSessionState";
import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionState } from "../../enums/RaceSessionState";
import { RaceSessionType } from "../../enums/RaceSessionType";
export interface SPluginsRaceClassification {
  m_iSession: 0 | PractiseSessionType | RaceSessionType;
  m_iSessionSeries: number;
  m_iSessionState: 0 | PractiseSessionState | RaceSessionState;
  m_iSessionTime: number;
  m_iNumEntries: number;
}
