import { ConfigurationRate } from "../../enums/ConfigurationRate";
import { GameState } from "../../enums/GameState";
import { TrackState } from "../../enums/TrackState";
import { BaseInfo } from "./BaseInfo";
export interface PluginInfo extends BaseInfo {
  m_GameState: GameState;
  m_TrackState: TrackState;
  m_PluginRate: ConfigurationRate;
  m_PluginVersion: number;
}
