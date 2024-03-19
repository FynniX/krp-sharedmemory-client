import { PractiseSessionState } from "../../enums/PractiseSessionState";
import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionState } from "../../enums/RaceSessionState";
import { RaceSessionType } from "../../enums/RaceSessionType";
import { SessionGroup } from "../../enums/SessionGroup";
import { WeatherCondition } from "../../enums/WeatherCondition";
export interface SPluginsRaceSession {
    m_iSession: 0 | PractiseSessionType | RaceSessionType;
    m_iSessionSeries: number;
    m_iGroup1: SessionGroup;
    m_iGroup2: SessionGroup;
    m_iSessionState: 0 | PractiseSessionState | RaceSessionState;
    m_iSessionLength: number;
    m_iSessionNumLaps: number;
    m_iNumEntries: number;
    m_aiEntries: number[];
    m_aiGrid: number[];
    m_iConditions: WeatherCondition;
    m_fAirTemperature: number;
    m_fTrackTemperature: number;
}
