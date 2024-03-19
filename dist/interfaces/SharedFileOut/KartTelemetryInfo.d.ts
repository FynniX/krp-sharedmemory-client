import { SPluginsKartData } from "../SharedFileIn/SPluginsKartData";
import { BaseInfo } from "./BaseInfo";
export interface KartTelemetryInfo extends BaseInfo {
  _fTime: number;
  _fPos: number;
  m_KartData: SPluginsKartData;
}
