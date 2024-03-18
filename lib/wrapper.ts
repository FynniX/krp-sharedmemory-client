import { TypedEmitter } from "tiny-typed-emitter";
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
import { addon } from "./binding";
import { Config } from "./interfaces/Config";
import { ConfigDelay } from "./enums/ConfigDelay";
import { GameState } from "./enums/GameState";

export const MINIMUM_PLUGIN_VERSION = 12;

export class Wrapper extends TypedEmitter<Events> {
    public activated: boolean = false
    private readonly config: Config

    public pluginInfo: PluginInfo | undefined
    public kartEventInfo: KartEventInfo | undefined
    public kartSessionInfo: KartSessionInfo | undefined
    public kartLapsInfo: KartLapsInfo | undefined
    public kartSplitsInfo: KartSplitsInfo | undefined
    public kartTelemetryInfo: KartTelemetryInfo | undefined
    public trackSegmentsInfo: TrackSegmentsInfo | undefined
    public raceEventInfo: RaceEventInfo | undefined
    public raceEntriesInfo: RaceEntriesInfo | undefined
    public raceSessionInfo: RaceSessionInfo | undefined
    public raceLapsInfo: RaceLapsInfo | undefined
    public raceSplitsInfo: RaceSplitsInfo | undefined
    public raceSpeedsInfo: RaceSpeedsInfo | undefined
    public raceCommunicationsInfo: RaceCommunicationsInfo | undefined
    public raceClassificationInfo: RaceClassificationInfo | undefined
    public raceTrackPositionsInfo: RaceTrackPositionsInfo | undefined
    public raceVehiclesDataInfo: RaceVehiclesDataInfo | undefined
    public camerasInfo: CamerasInfo | undefined

    constructor(config: Config = { ConnectDelay: ConfigDelay.SLOWEST, ReconnectDelay: ConfigDelay.SLOWEST, KeepAliveDelay: ConfigDelay.SLOWEST, UpdateDelay: ConfigDelay.NORMAL, logging: false }) {
        super()
        this.config = config
    }

    public activate(): void {
        if (this.activated) return
        this.activated = true
        this.connect()
    }

    public deactivate(): void {
        if (!this.activated) return;
        this.activated = false;

        this.pluginInfo = undefined
        this.kartEventInfo = undefined
        this.kartSessionInfo = undefined
        this.kartLapsInfo = undefined
        this.kartSplitsInfo = undefined
        this.kartTelemetryInfo = undefined
        this.trackSegmentsInfo = undefined
        this.raceEventInfo = undefined
        this.raceEntriesInfo = undefined
        this.raceSessionInfo = undefined
        this.raceLapsInfo = undefined
        this.raceSplitsInfo = undefined
        this.raceSpeedsInfo = undefined
        this.raceCommunicationsInfo = undefined
        this.raceClassificationInfo = undefined
        this.raceTrackPositionsInfo = undefined
        this.raceVehiclesDataInfo = undefined
        this.camerasInfo = undefined

        if (this.isConnected())
            this.disconnect()
    }

    public isConnected(): boolean {
        return addon.isConnected();
    }

    private connect(): void {
        if (!this.activated || this.isConnected()) return;

        if (addon.connect()) {
            this.config.logging && console.log("CONNECTED")
            this.emit("connected")

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

            return
        }

        this.config.logging && console.log("FAILED TO CONNECT")
        setTimeout(() => this.connect(), this.config.ConnectDelay)
    }

    private disconnect(reason: string = ""): void {
        addon.disconnect();
        this.config.logging && console.log("DISCONNECTED")
        this.emit("disconnected", reason)
        if (!this.activated) return
        setTimeout(() => this.connect(), this.config.ReconnectDelay)
    }

    private keepAlive(): void {
        if (!this.activated || !this.isConnected()) return

        this.pluginInfo = addon.getPluginInfo()
        this.emit('pluginInfo', this.pluginInfo)

        // Disconnect when GameState = CLOSED
        if (this.pluginInfo.m_GameState === GameState.CLOSED) {
            this.disconnect()
            return
        }

        // Check version of plugin
        if (this.pluginInfo.m_PluginVersion < MINIMUM_PLUGIN_VERSION) {
            this.config.logging && console.log(`Plugin version ${this.pluginInfo.m_PluginVersion} < ${MINIMUM_PLUGIN_VERSION}!`)
            this.disconnect(`Plugin version ${this.pluginInfo.m_PluginVersion} < ${MINIMUM_PLUGIN_VERSION}!`)
            return
        }

        setTimeout(() => this.keepAlive(), this.config.KeepAliveDelay)
    }

    private updateKartEventInfo() {
        if (!this.activated || !this.isConnected()) return

        this.kartEventInfo = addon.getKartEventInfo()
        this.emit('kartEventInfo', this.kartEventInfo)

        setTimeout(() => this.updateKartEventInfo(), this.config.UpdateDelay)
    }

    private updateKartSessionInfo() {
        if (!this.activated || !this.isConnected()) return

        this.kartSessionInfo = addon.getKartSessionInfo()
        this.emit('kartSessionInfo', this.kartSessionInfo)

        setTimeout(() => this.updateKartSessionInfo(), this.config.UpdateDelay)
    }

    private updateKartLapsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.kartLapsInfo = addon.getKartLapsInfo()
        this.emit('kartLapsInfo', this.kartLapsInfo)

        setTimeout(() => this.updateKartLapsInfo(), this.config.UpdateDelay)
    }

    private updateKartSplitsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.kartSplitsInfo = addon.getKartSplitsInfo()
        this.emit('kartSplitsInfo', this.kartSplitsInfo)

        setTimeout(() => this.updateKartSplitsInfo(), this.config.UpdateDelay)
    }

    private updateKartTelemetryInfo() {
        if (!this.activated || !this.isConnected()) return

        this.kartTelemetryInfo = addon.getKartTelemetryInfo()
        this.emit('kartTelemetryInfo', this.kartTelemetryInfo)

        setTimeout(() => this.updateKartTelemetryInfo(), this.config.UpdateDelay)
    }

    private updateTrackSegmentsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.trackSegmentsInfo = addon.getTrackSegmentsInfo()
        this.emit('trackSegmentsInfo', this.trackSegmentsInfo)

        setTimeout(() => this.updateTrackSegmentsInfo(), this.config.UpdateDelay)
    }

    private updateRaceEventInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceEventInfo = addon.getRaceEventInfo()
        this.emit('raceEventInfo', this.raceEventInfo)

        setTimeout(() => this.updateRaceEventInfo(), this.config.UpdateDelay)
    }

    private updateRaceEntriesInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceEntriesInfo = addon.getRaceEntriesInfo()
        this.emit('raceEntriesInfo', this.raceEntriesInfo)

        setTimeout(() => this.updateRaceEntriesInfo(), this.config.UpdateDelay)
    }

    private updateRaceSessionInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceSessionInfo = addon.getRaceSessionInfo()
        this.emit('raceSessionInfo', this.raceSessionInfo)

        setTimeout(() => this.updateRaceSessionInfo(), this.config.UpdateDelay)
    }

    private updateRaceLapsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceLapsInfo = addon.getRaceLapsInfo()
        this.emit('raceLapsInfo', this.raceLapsInfo)

        setTimeout(() => this.updateRaceLapsInfo(), this.config.UpdateDelay)
    }

    private updateRaceSplitsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceSplitsInfo = addon.getRaceSplitsInfo()
        this.emit('raceSplitsInfo', this.raceSplitsInfo)

        setTimeout(() => this.updateRaceSplitsInfo(), this.config.UpdateDelay)
    }

    private updateRaceSpeedsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceSpeedsInfo = addon.getRaceSpeedsInfo()
        this.emit('raceSpeedsInfo', this.raceSpeedsInfo)

        setTimeout(() => this.updateRaceSpeedsInfo(), this.config.UpdateDelay)
    }

    private updateRaceClassificationInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceClassificationInfo = addon.getRaceClassificationInfo()
        this.emit('raceClassificationInfo', this.raceClassificationInfo)

        setTimeout(() => this.updateRaceClassificationInfo(), this.config.UpdateDelay)
    }

    private updateRaceTrackPositionsInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceTrackPositionsInfo = addon.getRaceTrackPositionsInfo()
        this.emit('raceTrackPositionsInfo', this.raceTrackPositionsInfo)

        setTimeout(() => this.updateRaceTrackPositionsInfo(), this.config.UpdateDelay)
    }

    private updateRaceVehiclesDataInfo() {
        if (!this.activated || !this.isConnected()) return

        this.raceVehiclesDataInfo = addon.getRaceVehiclesDataInfo()
        this.emit('raceVehiclesDataInfo', this.raceVehiclesDataInfo)

        setTimeout(() => this.updateRaceVehiclesDataInfo(), this.config.UpdateDelay)
    }

    private updateCamerasInfo() {
        if (!this.activated || !this.isConnected()) return

        this.camerasInfo = addon.getCamerasInfo()
        this.emit('camerasInfo', this.camerasInfo)

        setTimeout(() => this.updateCamerasInfo(), this.config.UpdateDelay)
    }

    public spectateVehicle(vehicle: number) {
        if (!this.activated || !this.isConnected()) return
        addon.setVehicle(vehicle)
    }

    public spectateCamera(camera: number) {
        if (!this.activated || !this.isConnected()) return
        addon.setCamera(camera)
    }
}

export default Wrapper;