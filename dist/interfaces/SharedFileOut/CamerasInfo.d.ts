import { SPluginsSpectateVehicle } from "../SharedFileIn/SPluginsSpectateVehicle";
import { BaseInfo } from "./BaseInfo";
export interface CamerasInfo extends BaseInfo {
    currentVehicle: number;
    currentCamera: number;
    _iNumVehicles: number;
    _iNumCameras: number;
    m_Vehicles: SPluginsSpectateVehicle[];
    m_CameraNames: string[];
}
