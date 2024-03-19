import { SPluginsRaceSpeed } from "../SharedFileIn/SPluginsRaceSpeed";
import { BaseInfo } from "./BaseInfo";
export interface RaceSpeedsInfo extends BaseInfo {
  m_RaceSpeeds: SPluginsRaceSpeed[];
}
