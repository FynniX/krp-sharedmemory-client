import { SPluginsRaceClassification } from "../SharedFileIn/SPluginsRaceClassification";
import { SPluginsRaceClassificationEntry } from "../SharedFileIn/SPluginsRaceClassificationEntry";
import { BaseInfo } from "./BaseInfo";

export interface RaceClassificationInfo extends BaseInfo {
  m_RaceClassification: SPluginsRaceClassification;
  m_RaceClassificationEntries: SPluginsRaceClassificationEntry[];
}
