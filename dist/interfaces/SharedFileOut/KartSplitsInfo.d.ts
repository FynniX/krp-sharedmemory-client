import { SPluginsRaceSplit } from "../SharedFileIn/SPluginsRaceSplit";
import { BaseInfo } from "./BaseInfo";
export interface KartSplitsInfo extends BaseInfo {
  _iNumSplits: number;
  m_KartSplits: SPluginsRaceSplit[];
}
