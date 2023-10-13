import { SPluginsRaceCommunication } from "./SPluginsRaceCommunication";
import { SPluginsRaceLap } from "./SPluginsRaceLap";
import { SPluginsRaceSpeed } from "./SPluginsRaceSpeed";
import { SPluginsRaceSplit } from "./SPluginsRaceSplit";
import { SPluginsRaceVehicleData } from "./SPluginsRaceVehicleData";

export type SPluginsRaceClassificationEntry = {
  m_iRaceNum: number;
  m_iState: number;
  m_iBestLap: number;
  m_LastLap: SPluginsRaceLap;
  m_LastSplit: SPluginsRaceSplit;
  m_LastSpeed: SPluginsRaceSpeed;
  m_LastCommunication: SPluginsRaceCommunication;
  m_LastVehicleData: SPluginsRaceVehicleData;
  m_fBestSpeed: number;
  m_iBestLapNum: number;
  m_iNumLaps: number;
  m_iGap: number;
  m_iGapLaps: number;
  m_iPenalty: number;
  m_iPit: number;
}