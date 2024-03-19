import { SPluginsRaceSplit } from "../SharedFileIn/SPluginsRaceSplit";
import { BaseInfo } from "./BaseInfo";

export interface RaceSplitsInfo extends BaseInfo {
  _iNumSplits: number;
  m_RaceSplits: SPluginsRaceSplit[];
}
