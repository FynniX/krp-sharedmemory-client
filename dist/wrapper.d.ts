import { Emitter } from "./emitter";
import { Events } from "./interfaces/Events";
import { KartEventInfo } from "./interfaces/SharedFileOut/KartEventInfo";
import { KartLapsInfo } from "./interfaces/SharedFileOut/KartLapsInfo";
import { KartSessionInfo } from "./interfaces/SharedFileOut/KartSessionInfo";
import { KartSplitsInfo } from "./interfaces/SharedFileOut/KartSplitsInfo";
import { KartTelemetryInfo } from "./interfaces/SharedFileOut/KartTelemetryInfo";
import { PluginInfo } from "./interfaces/SharedFileOut/PluginInfo";
import { RaceClassificationInfo } from "./interfaces/SharedFileOut/RaceClassificationInfo";
import { RaceCommunicationsInfo } from "./interfaces/SharedFileOut/RaceCommunicationsInfo";
import { RaceEntriesInfo } from "./interfaces/SharedFileOut/RaceEntriesInfo";
import { RaceEventInfo } from "./interfaces/SharedFileOut/RaceEventInfo";
import { RaceLapsInfo } from "./interfaces/SharedFileOut/RaceLapsInfo";
import { RaceSessionInfo } from "./interfaces/SharedFileOut/RaceSessionInfo";
import { RaceSpeedsInfo } from "./interfaces/SharedFileOut/RaceSpeedsInfo";
import { RaceSplitsInfo } from "./interfaces/SharedFileOut/RaceSplitsInfo";
import { RaceTrackPositionsInfo } from "./interfaces/SharedFileOut/RaceTrackPositionsInfo";
import { RaceVehiclesDataInfo } from "./interfaces/SharedFileOut/RaceVehiclesDataInfo";
import { TrackSegmentsInfo } from "./interfaces/SharedFileOut/TrackSegmentsInfo";
import { CamerasInfo } from "./interfaces/SharedFileOut/CamerasInfo";
import { Config } from "./interfaces/Config";
export declare const MINIMUM_PLUGIN_VERSION = 12;
export declare class Wrapper extends Emitter<Events> {
    /**
     * Weather or not the wrapper is activated.
     * @type {boolean}
     */
    activated: boolean;
    /**
     * Configuration for the wrapper.
     * @type {Config}
     * @readonly
     * @private
     */
    private readonly config;
    /**
     * Latest PluginInfo from the wrapper.
     * @type {PluginInfo | undefined}
     */
    pluginInfo: PluginInfo | undefined;
    /**
     * Latest KartEventInfo from the wrapper.
     * @type {KartEventInfo | undefined}
     */
    kartEventInfo: KartEventInfo | undefined;
    /**
     * Latest KartSessionInfo from the wrapper.
     * @type {KartSessionInfo | undefined}
     */
    kartSessionInfo: KartSessionInfo | undefined;
    /**
     * Latest KartLapsInfo from the wrapper.
     * @type {KartLapsInfo | undefined}
     */
    kartLapsInfo: KartLapsInfo | undefined;
    /**
     * Latest KartSplitsInfo from the wrapper.
     * @type {KartSplitsInfo | undefined}
     */
    kartSplitsInfo: KartSplitsInfo | undefined;
    /**
     * Latest KartTelemetryInfo from the wrapper.
     * @type {KartTelemetryInfo | undefined}
     */
    kartTelemetryInfo: KartTelemetryInfo | undefined;
    /**
     * Latest TrackSegmentsInfo from the wrapper.
     * @type {TrackSegmentsInfo | undefined}
     */
    trackSegmentsInfo: TrackSegmentsInfo | undefined;
    /**
     * Latest RaceEventInfo from the wrapper.
     * @type {RaceEventInfo | undefined}
     */
    raceEventInfo: RaceEventInfo | undefined;
    /**
     * Latest RaceEntriesInfo from the wrapper.
     * @type {RaceEntriesInfo | undefined}
     */
    raceEntriesInfo: RaceEntriesInfo | undefined;
    /**
     * Latest RaceSessionInfo from the wrapper.
     * @type {RaceSessionInfo | undefined}
     */
    raceSessionInfo: RaceSessionInfo | undefined;
    /**
     * Latest RaceLapsInfo from the wrapper.
     * @type {RaceLapsInfo | undefined}
     */
    raceLapsInfo: RaceLapsInfo | undefined;
    /**
     * Latest RaceSplitsInfo from the wrapper.
     * @type {RaceSplitsInfo | undefined}
     */
    raceSplitsInfo: RaceSplitsInfo | undefined;
    /**
     * Latest RaceSpeedsInfo from the wrapper.
     * @type {RaceSpeedsInfo | undefined}
     */
    raceSpeedsInfo: RaceSpeedsInfo | undefined;
    /**
     * Latest RaceCommunicationsInfo from the wrapper.
     * @type {RaceCommunicationsInfo | undefined}
     */
    raceCommunicationsInfo: RaceCommunicationsInfo | undefined;
    /**
     * Latest RaceClassificationInfo from the wrapper.
     * @type {RaceClassificationInfo | undefined}
     */
    raceClassificationInfo: RaceClassificationInfo | undefined;
    /**
     * Latest RaceTrackPositionsInfo from the wrapper.
     * @type {RaceTrackPositionsInfo | undefined}
     */
    raceTrackPositionsInfo: RaceTrackPositionsInfo | undefined;
    /**
     * Latest RaceVehiclesDataInfo from the wrapper.
     * @type {RaceVehiclesDataInfo | undefined}
     */
    raceVehiclesDataInfo: RaceVehiclesDataInfo | undefined;
    /**
     * Latest CamerasInfo from the wrapper.
     * @type {CamerasInfo | undefined}
     */
    camerasInfo: CamerasInfo | undefined;
    /**
     * Creates an instance of wrapper.
     * @constructor
     * @param {Config} config - Configuration
     */
    constructor(config?: Config);
    /**
     * Activates the wrapper.
     * @returns {void}
     */
    activate(): void;
    /**
     * Deactivates the wrapper.
     * @returns {void}
     */
    deactivate(): void;
    /**
     * Returns if the wrapper is connected.
     * @returns {boolean}
     */
    isConnected(): boolean;
    /**
     * Tries to connect the wrapper.
     * @private
     * @returns {void}
     */
    private connect;
    /**
     * Disconnects the wrapper.
     * @private
     * @param {string} reason - Reason for disconnect
     * @returns
     */
    private disconnect;
    /**
     * Checks if plugin is still alive.
     * @private
     * @returns {void}
     */
    private keepAlive;
    /**
     * Updates the KartEventInfo Event.
     * @private
     * @returns {void}
     */
    private updateKartEventInfo;
    /**
     * Updates the KartSessionInfo Event.
     * @private
     * @returns {void}
     */
    private updateKartSessionInfo;
    /**
     * Updates the KartLapsInfo Event.
     * @private
     * @returns {void}
     */
    private updateKartLapsInfo;
    /**
     * Updates the KartSplitsInfo Event.
     * @private
     * @returns {void}
     */
    private updateKartSplitsInfo;
    /**
     * Updates the KartTelemetryInfo Event.
     * @private
     * @returns {void}
     */
    private updateKartTelemetryInfo;
    /**
     * Updates the TrackSegmentsInfo Event.
     * @private
     * @returns {void}
     */
    private updateTrackSegmentsInfo;
    /**
     * Updates the RaceEventInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceEventInfo;
    /**
     * Updates the RaceEntriesInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceEntriesInfo;
    /**
     * Updates the RaceSessionInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceSessionInfo;
    /**
     * Updates the RaceLapsInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceLapsInfo;
    /**
     * Updates the RaceSplitsInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceSplitsInfo;
    /**
     * Updates the RaceSpeedsInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceSpeedsInfo;
    /**
     * Updates the RaceClassificationInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceClassificationInfo;
    /**
     * Updates the RaceTrackPositionsInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceTrackPositionsInfo;
    /**
     * Updates the RaceVehiclesDataInfo Event.
     * @private
     * @returns {void}
     */
    private updateRaceVehiclesDataInfo;
    /**
     * Updates the CamerasInfo Event.
     * @private
     * @returns {void}
     */
    private updateCamerasInfo;
    /**
     * Set the vehicle to spectate.
     * @param vehicle - The vehicle id to spectate.
     * @returns {void}
     */
    spectateVehicle(vehicle: number): void;
    /**
     * Set the camera to spectate.
     * @param camera - The camera id to spectate.
     * @returns {void}
     */
    spectateCamera(camera: number): void;
}
export default Wrapper;
