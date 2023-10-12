import { SPluginsRaceLap } from "./SPluginsRaceLap";

export type SPluginsRaceClassificationEntry = {
  m_iRaceNum: number;
  m_iState: number;
  m_iBestLap: number;
  m_LastLap: SPluginsRaceLap;
  m_fBestSpeed: number;
  m_iBestLapNum: number;
  m_iNumLaps: number;
  m_iGap: number;
  m_iGapLaps: number;
  m_iPenalty: number;
  m_iPit: number;
}