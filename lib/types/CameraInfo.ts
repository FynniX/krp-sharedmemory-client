import type { CameraCamerasInfo } from "./CameraCamerasInfo";
import type { CameraVehiclesInfo } from "./CameraVehiclesInfo";

export type CameraInfo = {
    m_id: number;
    m_VehiclesInfo: CameraVehiclesInfo;
    m_CamerasInfo: CameraCamerasInfo;
}