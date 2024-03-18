import { SPluginsRaceAddEntry } from "../SharedFileIn/SPluginsRaceAddEntry";
import { BaseInfo } from "./BaseInfo";

export interface RaceEntriesInfo extends BaseInfo {
    _iNumEntries: number;
    m_RaceEntries: SPluginsRaceAddEntry[];
}