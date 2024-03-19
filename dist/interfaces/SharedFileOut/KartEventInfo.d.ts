import { SPluginsKartEvent } from "../SharedFileIn/SPluginsKartEvent";
import { BaseInfo } from "./BaseInfo";
export interface KartEventInfo extends BaseInfo {
  m_KartEvent: SPluginsKartEvent;
}
