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
  /**
   * Weather or not the wrapper is activated.
   * @type {boolean}
   */
  public activated: boolean = false;

  /**
   * Configuration for the wrapper.
   * @type {Config}
   * @readonly
   * @private
   */
  private readonly config: Config;

  /**
   * Latest PluginInfo from the wrapper.
   * @type {PluginInfo | undefined}
   */
  public pluginInfo: PluginInfo | undefined;

  /**
   * Latest KartEventInfo from the wrapper.
   * @type {KartEventInfo | undefined}
   */
  public kartEventInfo: KartEventInfo | undefined;

  /**
   * Latest KartSessionInfo from the wrapper.
   * @type {KartSessionInfo | undefined}
   */
  public kartSessionInfo: KartSessionInfo | undefined;

  /**
   * Latest KartLapsInfo from the wrapper.
   * @type {KartLapsInfo | undefined}
   */
  public kartLapsInfo: KartLapsInfo | undefined;

  /**
   * Latest KartSplitsInfo from the wrapper.
   * @type {KartSplitsInfo | undefined}
   */
  public kartSplitsInfo: KartSplitsInfo | undefined;

  /**
   * Latest KartTelemetryInfo from the wrapper.
   * @type {KartTelemetryInfo | undefined}
   */
  public kartTelemetryInfo: KartTelemetryInfo | undefined;

  /**
   * Latest TrackSegmentsInfo from the wrapper.
   * @type {TrackSegmentsInfo | undefined}
   */
  public trackSegmentsInfo: TrackSegmentsInfo | undefined;

  /**
   * Latest RaceEventInfo from the wrapper.
   * @type {RaceEventInfo | undefined}
   */
  public raceEventInfo: RaceEventInfo | undefined;

  /**
   * Latest RaceEntriesInfo from the wrapper.
   * @type {RaceEntriesInfo | undefined}
   */
  public raceEntriesInfo: RaceEntriesInfo | undefined;

  /**
   * Latest RaceSessionInfo from the wrapper.
   * @type {RaceSessionInfo | undefined}
   */
  public raceSessionInfo: RaceSessionInfo | undefined;

  /**
   * Latest RaceLapsInfo from the wrapper.
   * @type {RaceLapsInfo | undefined}
   */
  public raceLapsInfo: RaceLapsInfo | undefined;

  /**
   * Latest RaceSplitsInfo from the wrapper.
   * @type {RaceSplitsInfo | undefined}
   */
  public raceSplitsInfo: RaceSplitsInfo | undefined;

  /**
   * Latest RaceSpeedsInfo from the wrapper.
   * @type {RaceSpeedsInfo | undefined}
   */
  public raceSpeedsInfo: RaceSpeedsInfo | undefined;

  /**
   * Latest RaceCommunicationsInfo from the wrapper.
   * @type {RaceCommunicationsInfo | undefined}
   */
  public raceCommunicationsInfo: RaceCommunicationsInfo | undefined;

  /**
   * Latest RaceClassificationInfo from the wrapper.
   * @type {RaceClassificationInfo | undefined}
   */
  public raceClassificationInfo: RaceClassificationInfo | undefined;

  /**
   * Latest RaceTrackPositionsInfo from the wrapper.
   * @type {RaceTrackPositionsInfo | undefined}
   */
  public raceTrackPositionsInfo: RaceTrackPositionsInfo | undefined;

  /**
   * Latest RaceVehiclesDataInfo from the wrapper.
   * @type {RaceVehiclesDataInfo | undefined}
   */
  public raceVehiclesDataInfo: RaceVehiclesDataInfo | undefined;

  /**
   * Latest CamerasInfo from the wrapper.
   * @type {CamerasInfo | undefined}
   */
  public camerasInfo: CamerasInfo | undefined;

  /**
   * Creates an instance of wrapper.
   * @constructor
   * @param {Config} config - Configuration
   */
  constructor(
    config: Config = {
      ConnectDelay: ConfigDelay.SLOWEST,
      ReconnectDelay: ConfigDelay.SLOWEST,
      KeepAliveDelay: ConfigDelay.SLOWEST,
      UpdateDelay: ConfigDelay.FAST,
      logging: false,
    },
  ) {
    super();
    this.config = config;
  }

  /**
   * Activates the wrapper.
   * @returns {void}
   */
  public activate(): void {
    if (this.activated) return;
    this.activated = true;
    this.connect();
  }

  /**
   * Deactivates the wrapper.
   * @returns {void}
   */
  public deactivate(): void {
    if (!this.activated) return;
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

    if (this.isConnected()) this.disconnect();
  }

  /**
   * Returns if the wrapper is connected.
   * @returns {boolean}
   */
  public isConnected(): boolean {
    return addon.isConnected();
  }

  /**
   * Tries to connect the wrapper.
   * @private
   * @returns {void}
   */
  private connect(): void {
    if (!this.activated || this.isConnected()) return;

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
  private disconnect(reason: string = ""): void {
    addon.disconnect();
    this.config.logging && console.log("DISCONNECTED");
    this.emit("disconnected", reason);
    if (!this.activated) return;
    setTimeout(() => this.connect(), this.config.ReconnectDelay);
  }

  /**
   * Checks if plugin is still alive.
   * @private
   * @returns {void}
   */
  private keepAlive(): void {
    if (!this.activated || !this.isConnected()) return;

    this.pluginInfo = addon.getPluginInfo();
    this.emit("pluginInfo", this.pluginInfo);

    // Disconnect when GameState = CLOSED
    if (this.pluginInfo.m_GameState === GameState.CLOSED) {
      this.disconnect();
      return;
    }

    // Check version of plugin
    if (this.pluginInfo.m_PluginVersion < MINIMUM_PLUGIN_VERSION) {
      this.config.logging &&
        console.log(
          `Plugin version ${this.pluginInfo.m_PluginVersion} < ${MINIMUM_PLUGIN_VERSION}!`,
        );
      this.disconnect(
        `Plugin version ${this.pluginInfo.m_PluginVersion} < ${MINIMUM_PLUGIN_VERSION}!`,
      );
      return;
    }

    setTimeout(() => this.keepAlive(), this.config.KeepAliveDelay);
  }

  /**
   * Updates the KartEventInfo Event.
   * @private
   * @returns {void}
   */
  private updateKartEventInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.kartEventInfo = addon.getKartEventInfo();
    this.emit("kartEventInfo", this.kartEventInfo);
    setTimeout(() => this.updateKartEventInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the KartSessionInfo Event.
   * @private
   * @returns {void}
   */
  private updateKartSessionInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.kartSessionInfo = addon.getKartSessionInfo();
    this.emit("kartSessionInfo", this.kartSessionInfo);
    setTimeout(() => this.updateKartSessionInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the KartLapsInfo Event.
   * @private
   * @returns {void}
   */
  private updateKartLapsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.kartLapsInfo = addon.getKartLapsInfo();
    this.emit("kartLapsInfo", this.kartLapsInfo);
    setTimeout(() => this.updateKartLapsInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the KartSplitsInfo Event.
   * @private
   * @returns {void}
   */
  private updateKartSplitsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.kartSplitsInfo = addon.getKartSplitsInfo();
    this.emit("kartSplitsInfo", this.kartSplitsInfo);
    setTimeout(() => this.updateKartSplitsInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the KartTelemetryInfo Event.
   * @private
   * @returns {void}
   */
  private updateKartTelemetryInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.kartTelemetryInfo = addon.getKartTelemetryInfo();
    this.emit("kartTelemetryInfo", this.kartTelemetryInfo);
    setTimeout(() => this.updateKartTelemetryInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the TrackSegmentsInfo Event.
   * @private
   * @returns {void}
   */
  private updateTrackSegmentsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.trackSegmentsInfo = addon.getTrackSegmentsInfo();
    this.emit("trackSegmentsInfo", this.trackSegmentsInfo);
    setTimeout(() => this.updateTrackSegmentsInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceEventInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceEventInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceEventInfo = addon.getRaceEventInfo();
    this.emit("raceEventInfo", this.raceEventInfo);
    setTimeout(() => this.updateRaceEventInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceEntriesInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceEntriesInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceEntriesInfo = addon.getRaceEntriesInfo();
    this.emit("raceEntriesInfo", this.raceEntriesInfo);
    setTimeout(() => this.updateRaceEntriesInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceSessionInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceSessionInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceSessionInfo = addon.getRaceSessionInfo();
    this.emit("raceSessionInfo", this.raceSessionInfo);
    setTimeout(() => this.updateRaceSessionInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceLapsInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceLapsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceLapsInfo = addon.getRaceLapsInfo();
    this.emit("raceLapsInfo", this.raceLapsInfo);
    setTimeout(() => this.updateRaceLapsInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceSplitsInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceSplitsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceSplitsInfo = addon.getRaceSplitsInfo();
    this.emit("raceSplitsInfo", this.raceSplitsInfo);
    setTimeout(() => this.updateRaceSplitsInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceSpeedsInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceSpeedsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceSpeedsInfo = addon.getRaceSpeedsInfo();
    this.emit("raceSpeedsInfo", this.raceSpeedsInfo);
    setTimeout(() => this.updateRaceSpeedsInfo(), this.config.UpdateDelay);
  }

  /**
   * Updates the RaceClassificationInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceClassificationInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceClassificationInfo = addon.getRaceClassificationInfo();
    this.emit("raceClassificationInfo", this.raceClassificationInfo);
    setTimeout(
      () => this.updateRaceClassificationInfo(),
      this.config.UpdateDelay,
    );
  }

  /**
   * Updates the RaceTrackPositionsInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceTrackPositionsInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceTrackPositionsInfo = addon.getRaceTrackPositionsInfo();
    this.emit("raceTrackPositionsInfo", this.raceTrackPositionsInfo);
    setTimeout(
      () => this.updateRaceTrackPositionsInfo(),
      this.config.UpdateDelay,
    );
  }

  /**
   * Updates the RaceVehiclesDataInfo Event.
   * @private
   * @returns {void}
   */
  private updateRaceVehiclesDataInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.raceVehiclesDataInfo = addon.getRaceVehiclesDataInfo();
    this.emit("raceVehiclesDataInfo", this.raceVehiclesDataInfo);
    setTimeout(
      () => this.updateRaceVehiclesDataInfo(),
      this.config.UpdateDelay,
    );
  }

  /**
   * Updates the CamerasInfo Event.
   * @private
   * @returns {void}
   */
  private updateCamerasInfo() {
    if (!this.activated || !this.isConnected()) return;
    this.camerasInfo = addon.getCamerasInfo();
    this.emit("camerasInfo", this.camerasInfo);
    setTimeout(() => this.updateCamerasInfo(), this.config.UpdateDelay);
  }

  /**
   * Set the vehicle to spectate.
   * @param vehicle - The vehicle id to spectate.
   * @returns {void}
   */
  public spectateVehicle(vehicle: number): void {
    if (!this.activated || !this.isConnected()) return;
    addon.setVehicle(vehicle);
  }

  /**
   * Set the camera to spectate.
   * @param camera - The camera id to spectate.
   * @returns {void}
   */
  public spectateCamera(camera: number): void {
    if (!this.activated || !this.isConnected()) return;
    addon.setCamera(camera);
  }
}

export default Wrapper;
