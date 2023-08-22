import {SPluginsRaceClassificationEntry} from './SPluginsRaceClassificationEntry'
import {SPluginsRaceClassification} from './SPluginsRaceClassification'

export type RaceClassificationInfo = {
  m_id: number;
  m_RaceClassification: SPluginsRaceClassification;
  m_RaceEntries: SPluginsRaceClassificationEntry[];
}