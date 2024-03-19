import { DriveType } from "../../enums/DriveType";
import { EngineCooling } from "../../enums/EngineCooling";
import { EventType } from "../../enums/EventType";

export interface SPluginsKartEvent {
  m_szDriverName: string;
  m_szKartID: string;
  m_szKartName: string;
  m_iDriveType: DriveType;
  m_iNumberOfGears: number;
  m_iMaxRPM: number;
  m_iLimiter: number;
  m_iShiftRPM: number;
  m_iEngineCooling: EngineCooling;
  m_fEngineOptTemperature: number;
  m_afEngineTemperatureAlarm: number[];
  m_fMaxFuel: number;
  m_szCategory: string;
  m_szDash: string;
  m_szTrackID: string;
  m_szTrackName: string;
  m_fTrackLength: number;
  m_iType: EventType;
}
