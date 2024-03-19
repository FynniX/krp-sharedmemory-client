import { SPluginsRaceVehicleData } from "../SharedFileIn/SPluginsRaceVehicleData";
import { BaseInfo } from "./BaseInfo";
export interface RaceVehiclesDataInfo extends BaseInfo {
    m_RaceVehiclesData: SPluginsRaceVehicleData[];
}
