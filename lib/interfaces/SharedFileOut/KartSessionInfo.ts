import { SPluginsKartSession } from "../SharedFileIn/SPluginsKartSession";
import { BaseInfo } from "./BaseInfo";

export interface KartSessionInfo extends BaseInfo {
  m_KartSession: SPluginsKartSession;
}
