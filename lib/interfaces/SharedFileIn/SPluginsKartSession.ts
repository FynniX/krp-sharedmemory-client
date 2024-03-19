import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionType } from "../../enums/RaceSessionType";
import { WeatherCondition } from "../../enums/WeatherCondition";

export interface SPluginsKartSession {
  m_iSession: 0 | PractiseSessionType | RaceSessionType;
  m_iSessionSeries: number;
  m_iConditions: WeatherCondition;
  m_fAirTemperature: number;
  m_fTrackTemperature: number;
  m_szSetupFileName: string;
}
