import { TypedEmitter } from "tiny-typed-emitter";
import { addon } from "./binding";
import { ConfigDelay } from "./enums/ConfigDelay";
import { GameState } from "./enums/GameState";
export const MINIMUM_PLUGIN_VERSION = 12;
export class Wrapper extends TypedEmitter {
    /**
     * Creates an instance of wrapper.
     * @constructor
     * @param {Config} config - Configuration
     */
    constructor(config = {
        ConnectDelay: ConfigDelay.SLOWEST,
        ReconnectDelay: ConfigDelay.SLOWEST,
        KeepAliveDelay: ConfigDelay.SLOWEST,
        UpdateDelay: ConfigDelay.FAST,
        logging: false,
    }) {
        super();
        /**
         * Weather or not the wrapper is activated.
         * @type {boolean}
         */
        this.activated = false;
        this.config = config;
    }
    /**
     * Activates the wrapper.
     * @returns {void}
     */
    activate() {
        if (this.activated)
            return;
        this.activated = true;
        this.connect();
    }
    /**
     * Deactivates the wrapper.
     * @returns {void}
     */
    deactivate() {
        if (!this.activated)
            return;
        this.activated = false;
        this.pluginInfo = undefined;
        this.kartEventInfo = undefined;
        this.kartSessionInfo = undefined;
        this.kartLapsInfo = undefined;
        this.kartSplitsInfo = undefined;
        this.kartTelemetryInfo = undefined;
        this.trackSegmentsInfo = undefined;
        this.raceEventInfo = undefined;
        this.raceEntriesInfo = undefined;
        this.raceSessionInfo = undefined;
        this.raceLapsInfo = undefined;
        this.raceSplitsInfo = undefined;
        this.raceSpeedsInfo = undefined;
        this.raceCommunicationsInfo = undefined;
        this.raceClassificationInfo = undefined;
        this.raceTrackPositionsInfo = undefined;
        this.raceVehiclesDataInfo = undefined;
        this.camerasInfo = undefined;
        if (this.isConnected())
            this.disconnect();
    }
    /**
     * Returns if the wrapper is connected.
     * @returns {boolean}
     */
    isConnected() {
        return addon.isConnected();
    }
    /**
     * Tries to connect the wrapper.
     * @private
     * @returns {void}
     */
    connect() {
        if (!this.activated || this.isConnected())
            return;
        if (addon.connect()) {
            this.config.logging && console.log("CONNECTED");
            this.emit("connected");
            // Start events
            this.keepAlive();
            this.updateKartEventInfo();
            this.updateKartSessionInfo();
            this.updateKartLapsInfo();
            this.updateKartSplitsInfo();
            this.updateKartTelemetryInfo();
            this.updateTrackSegmentsInfo();
            this.updateRaceEventInfo();
            this.updateRaceEntriesInfo();
            this.updateRaceSessionInfo();
            this.updateRaceLapsInfo();
            this.updateRaceSplitsInfo();
            this.updateRaceSpeedsInfo();
            this.updateRaceClassificationInfo();
            this.updateRaceTrackPositionsInfo();
            this.updateRaceVehiclesDataInfo();
            this.updateCamerasInfo();
            return;
        }
        this.config.logging && console.log("FAILED TO CONNECT");
        setTimeout(() => this.connect(), this.config.ConnectDelay);
    }
    /**
     * Disconnects the wrapper.
     * @private
     * @param {string} reason - Reason for disconnect
     * @returns
     */
    disconnect(reason = "") {
        addon.disconnect();
        this.config.logging && console.log("DISCONNECTED");
        this.emit("disconnected", reason);
        if (!this.activated)
            return;
        setTimeout(() => this.connect(), this.config.ReconnectDelay);
    }
    /**
     * Checks if plugin is still alive.
     * @private
     * @returns {void}
     */
    keepAlive() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.pluginInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.pluginInfo = addon.getPluginInfo();
        lastId !== ((_b = this.pluginInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("pluginInfo", this.pluginInfo);
        // Disconnect when GameState = CLOSED
        if (this.pluginInfo.m_GameState === GameState.CLOSED) {
            this.disconnect();
            return;
        }
        // Check version of plugin
        if (this.pluginInfo.m_PluginVersion < MINIMUM_PLUGIN_VERSION) {
            this.config.logging &&
                console.log(`Plugin version ${this.pluginInfo.m_PluginVersion} < ${MINIMUM_PLUGIN_VERSION}!`);
            this.disconnect(`Plugin version ${this.pluginInfo.m_PluginVersion} < ${MINIMUM_PLUGIN_VERSION}!`);
            return;
        }
        setTimeout(() => this.keepAlive(), this.config.KeepAliveDelay);
    }
    /**
     * Updates the KartEventInfo Event.
     * @private
     * @returns {void}
     */
    updateKartEventInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.kartEventInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.kartEventInfo = addon.getKartEventInfo();
        lastId !== ((_b = this.kartEventInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("kartEventInfo", this.kartEventInfo);
        setTimeout(() => this.updateKartEventInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the KartSessionInfo Event.
     * @private
     * @returns {void}
     */
    updateKartSessionInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.kartSessionInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.kartSessionInfo = addon.getKartSessionInfo();
        lastId !== ((_b = this.kartSessionInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("kartSessionInfo", this.kartSessionInfo);
        setTimeout(() => this.updateKartSessionInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the KartLapsInfo Event.
     * @private
     * @returns {void}
     */
    updateKartLapsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.kartLapsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.kartLapsInfo = addon.getKartLapsInfo();
        lastId !== ((_b = this.kartLapsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("kartLapsInfo", this.kartLapsInfo);
        setTimeout(() => this.updateKartLapsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the KartSplitsInfo Event.
     * @private
     * @returns {void}
     */
    updateKartSplitsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.kartSplitsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.kartSplitsInfo = addon.getKartSplitsInfo();
        lastId !== ((_b = this.kartSplitsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("kartSplitsInfo", this.kartSplitsInfo);
        setTimeout(() => this.updateKartSplitsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the KartTelemetryInfo Event.
     * @private
     * @returns {void}
     */
    updateKartTelemetryInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.kartTelemetryInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.kartTelemetryInfo = addon.getKartTelemetryInfo();
        lastId !== ((_b = this.kartTelemetryInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("kartTelemetryInfo", this.kartTelemetryInfo);
        setTimeout(() => this.updateKartTelemetryInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the TrackSegmentsInfo Event.
     * @private
     * @returns {void}
     */
    updateTrackSegmentsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.trackSegmentsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.trackSegmentsInfo = addon.getTrackSegmentsInfo();
        lastId !== ((_b = this.trackSegmentsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("trackSegmentsInfo", this.trackSegmentsInfo);
        setTimeout(() => this.updateTrackSegmentsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceEventInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceEventInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceEventInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceEventInfo = addon.getRaceEventInfo();
        lastId !== ((_b = this.raceEventInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceEventInfo", this.raceEventInfo);
        setTimeout(() => this.updateRaceEventInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceEntriesInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceEntriesInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceEntriesInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceEntriesInfo = addon.getRaceEntriesInfo();
        lastId !== ((_b = this.raceEntriesInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceEntriesInfo", this.raceEntriesInfo);
        setTimeout(() => this.updateRaceEntriesInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceSessionInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceSessionInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceSessionInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceSessionInfo = addon.getRaceSessionInfo();
        lastId !== ((_b = this.raceSessionInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceSessionInfo", this.raceSessionInfo);
        setTimeout(() => this.updateRaceSessionInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceLapsInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceLapsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceLapsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceLapsInfo = addon.getRaceLapsInfo();
        lastId !== ((_b = this.raceLapsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceLapsInfo", this.raceLapsInfo);
        setTimeout(() => this.updateRaceLapsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceSplitsInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceSplitsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceSplitsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceSplitsInfo = addon.getRaceSplitsInfo();
        lastId !== ((_b = this.raceSplitsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceSplitsInfo", this.raceSplitsInfo);
        setTimeout(() => this.updateRaceSplitsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceSpeedsInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceSpeedsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceSpeedsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceSpeedsInfo = addon.getRaceSpeedsInfo();
        lastId !== ((_b = this.raceSpeedsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceSpeedsInfo", this.raceSpeedsInfo);
        setTimeout(() => this.updateRaceSpeedsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceClassificationInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceClassificationInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceClassificationInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceClassificationInfo = addon.getRaceClassificationInfo();
        lastId !== ((_b = this.raceClassificationInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceClassificationInfo", this.raceClassificationInfo);
        setTimeout(() => this.updateRaceClassificationInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceTrackPositionsInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceTrackPositionsInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceTrackPositionsInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceTrackPositionsInfo = addon.getRaceTrackPositionsInfo();
        lastId !== ((_b = this.raceTrackPositionsInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceTrackPositionsInfo", this.raceTrackPositionsInfo);
        setTimeout(() => this.updateRaceTrackPositionsInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the RaceVehiclesDataInfo Event.
     * @private
     * @returns {void}
     */
    updateRaceVehiclesDataInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.raceVehiclesDataInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.raceVehiclesDataInfo = addon.getRaceVehiclesDataInfo();
        lastId !== ((_b = this.raceVehiclesDataInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("raceVehiclesDataInfo", this.raceVehiclesDataInfo);
        setTimeout(() => this.updateRaceVehiclesDataInfo(), this.config.UpdateDelay);
    }
    /**
     * Updates the CamerasInfo Event.
     * @private
     * @returns {void}
     */
    updateCamerasInfo() {
        var _a, _b;
        if (!this.activated || !this.isConnected())
            return;
        const lastId = ((_a = this.camerasInfo) === null || _a === void 0 ? void 0 : _a.m_id) || -1;
        this.camerasInfo = addon.getCamerasInfo();
        lastId !== ((_b = this.camerasInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("camerasInfo", this.camerasInfo);
        setTimeout(() => this.updateCamerasInfo(), this.config.UpdateDelay);
    }
    /**
     * Set the vehicle to spectate.
     * @param vehicle - The vehicle id to spectate.
     * @returns {void}
     */
    spectateVehicle(vehicle) {
        if (!this.activated || !this.isConnected())
            return;
        addon.setVehicle(vehicle);
    }
    /**
     * Set the camera to spectate.
     * @param camera - The camera id to spectate.
     * @returns {void}
     */
    spectateCamera(camera) {
        if (!this.activated || !this.isConnected())
            return;
        addon.setCamera(camera);
    }
}
export default Wrapper;
