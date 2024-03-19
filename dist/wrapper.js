"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Wrapper = exports.MINIMUM_PLUGIN_VERSION = void 0;
const tiny_typed_emitter_1 = require("tiny-typed-emitter");
const binding_1 = require("./binding");
const ConfigDelay_1 = require("./enums/ConfigDelay");
const GameState_1 = require("./enums/GameState");
exports.MINIMUM_PLUGIN_VERSION = 12;
class Wrapper extends tiny_typed_emitter_1.TypedEmitter {
    /**
     * Creates an instance of wrapper.
     * @constructor
     * @param {Config} config - Configuration
     */
    constructor(config = {
        ConnectDelay: ConfigDelay_1.ConfigDelay.SLOWEST,
        ReconnectDelay: ConfigDelay_1.ConfigDelay.SLOWEST,
        KeepAliveDelay: ConfigDelay_1.ConfigDelay.SLOWEST,
        UpdateDelay: ConfigDelay_1.ConfigDelay.FAST,
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
        return binding_1.addon.isConnected();
    }
    /**
     * Tries to connect the wrapper.
     * @private
     * @returns {void}
     */
    connect() {
        if (!this.activated || this.isConnected())
            return;
        if (binding_1.addon.connect()) {
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
        binding_1.addon.disconnect();
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
        this.pluginInfo = binding_1.addon.getPluginInfo();
        lastId !== ((_b = this.pluginInfo) === null || _b === void 0 ? void 0 : _b.m_id) &&
            this.emit("pluginInfo", this.pluginInfo);
        // Disconnect when GameState = CLOSED
        if (this.pluginInfo.m_GameState === GameState_1.GameState.CLOSED) {
            this.disconnect();
            return;
        }
        // Check version of plugin
        if (this.pluginInfo.m_PluginVersion < exports.MINIMUM_PLUGIN_VERSION) {
            this.config.logging &&
                console.log(`Plugin version ${this.pluginInfo.m_PluginVersion} < ${exports.MINIMUM_PLUGIN_VERSION}!`);
            this.disconnect(`Plugin version ${this.pluginInfo.m_PluginVersion} < ${exports.MINIMUM_PLUGIN_VERSION}!`);
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
        this.kartEventInfo = binding_1.addon.getKartEventInfo();
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
        this.kartSessionInfo = binding_1.addon.getKartSessionInfo();
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
        this.kartLapsInfo = binding_1.addon.getKartLapsInfo();
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
        this.kartSplitsInfo = binding_1.addon.getKartSplitsInfo();
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
        this.kartTelemetryInfo = binding_1.addon.getKartTelemetryInfo();
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
        this.trackSegmentsInfo = binding_1.addon.getTrackSegmentsInfo();
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
        this.raceEventInfo = binding_1.addon.getRaceEventInfo();
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
        this.raceEntriesInfo = binding_1.addon.getRaceEntriesInfo();
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
        this.raceSessionInfo = binding_1.addon.getRaceSessionInfo();
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
        this.raceLapsInfo = binding_1.addon.getRaceLapsInfo();
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
        this.raceSplitsInfo = binding_1.addon.getRaceSplitsInfo();
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
        this.raceSpeedsInfo = binding_1.addon.getRaceSpeedsInfo();
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
        this.raceClassificationInfo = binding_1.addon.getRaceClassificationInfo();
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
        this.raceTrackPositionsInfo = binding_1.addon.getRaceTrackPositionsInfo();
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
        this.raceVehiclesDataInfo = binding_1.addon.getRaceVehiclesDataInfo();
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
        this.camerasInfo = binding_1.addon.getCamerasInfo();
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
        binding_1.addon.setVehicle(vehicle);
    }
    /**
     * Set the camera to spectate.
     * @param camera - The camera id to spectate.
     * @returns {void}
     */
    spectateCamera(camera) {
        if (!this.activated || !this.isConnected())
            return;
        binding_1.addon.setCamera(camera);
    }
}
exports.Wrapper = Wrapper;
exports.default = Wrapper;
