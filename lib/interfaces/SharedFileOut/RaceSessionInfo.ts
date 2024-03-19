import { SPluginsRaceSession } from "../SharedFileIn/SPluginsRaceSession";
import { BaseInfo } from "./BaseInfo";

export interface RaceSessionInfo extends BaseInfo {
  m_RaceSession: SPluginsRaceSession;
}
