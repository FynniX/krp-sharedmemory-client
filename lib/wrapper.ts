import addon from './binding';
import {Config, DefaultConfig} from "./config";

import {TypedEmitter} from 'tiny-typed-emitter';
import {WrapperEvents} from "./interfaces/WrapperEvents";

import type {PluginInfo} from "./types/PluginInfo";
import type {KartEventInfo} from "./types/KartEventInfo";
import type {KartSessionInfo} from "./types/KartSessionInfo";
import type {KartLapInfo} from "./types/KartLapInfo";
import type {KartSplitInfo} from "./types/KartSplitInfo";
import type {KartTelemetryInfo} from "./types/KartTelemetryInfo";
import type {TrackSegmentInfo} from "./types/TrackSegmentInfo";
import type {RaceEventInfo} from "./types/RaceEventInfo";
import type {RaceAddEntryInfo} from "./types/RaceAddEntryInfo";
import type {RaceRemoveEntryInfo} from "./types/RaceRemoveEntryInfo";
import type {RaceSessionInfo} from "./types/RaceSessionInfo";
import type {RaceSessionStateInfo} from "./types/RaceSessionStateInfo";
import type {RaceLapInfo} from "./types/RaceLapInfo";
import type {RaceSplitInfo} from "./types/RaceSplitInfo";
import type {RaceSpeedInfo} from "./types/RaceSpeedInfo";
import type {RaceCommunicationInfo} from "./types/RaceCommunicationInfo";
import type {RaceClassificationInfo} from "./types/RaceClassificationInfo";
import type {RaceTrackPositionInfo} from "./types/RaceTrackPositionInfo";
import type {RaceVehicleDataInfo} from "./types/RaceVehicleDataInfo";
import type {RaceEntriesInfo} from "./types/RaceEntriesInfo";

class Wrapper extends TypedEmitter<WrapperEvents> {
  public activated: boolean = false;
  private readonly logging;
  private readonly config: Config;

  public pluginInfo: PluginInfo | null = null;
  public kartEventInfo: KartEventInfo | null = null;
  public kartSessionInfo: KartSessionInfo | null = null;
  public kartLapInfo: KartLapInfo | null = null;
  public kartSplitInfo: KartSplitInfo | null = null;
  public kartTelemetryInfo: KartTelemetryInfo | null = null;
  public trackSegmentInfo: TrackSegmentInfo | null = null;
  public raceEventInfo: RaceEventInfo | null = null;
  public raceEntriesInfo: RaceEntriesInfo | null = null;
  public raceAddEntryInfo: RaceAddEntryInfo | null = null;
  public raceRemoveEntryInfo: RaceRemoveEntryInfo | null = null;
  public raceSessionInfo: RaceSessionInfo | null = null;
  public raceSessionStateInfo: RaceSessionStateInfo | null = null;
  public raceLapInfo: RaceLapInfo | null = null;
  public raceSplitInfo: RaceSplitInfo | null = null;
  public raceSpeedInfo: RaceSpeedInfo | null = null;
  public raceCommunicationInfo: RaceCommunicationInfo | null = null;
  public raceClassificationInfo: RaceClassificationInfo | null = null;
  public raceTrackPositionInfo: RaceTrackPositionInfo | null = null;
  public raceVehicleDataInfo: RaceVehicleDataInfo | null = null;

  constructor(logging: boolean, Config: Config = DefaultConfig) {
    super();

    this.logging = logging;
    this.config = Config;

    // Needs 19 threads at least to work
    if (!process.env.UV_THREADPOOL_SIZE || Number(process.env.UV_THREADPOOL_SIZE) < 20) {
      this.logging && console.error('UV_THREADPOOL_SIZE needs to be higher than 20!')
      return
    }

    addon.setWaitDelay(this.config.Delays.WaitDelay)
  }

  public activate(): void {
    if (this.activated) return;
    this.activated = true;
    this.connect();
  }

  public deactivate(): void {
    if (!this.activated) return;
    this.activated = false;

    this.pluginInfo = null
    this.kartEventInfo = null
    this.kartSessionInfo = null
    this.kartLapInfo = null
    this.kartSplitInfo = null
    this.kartTelemetryInfo = null
    this.trackSegmentInfo = null
    this.raceEventInfo = null
    this.raceEntriesInfo = null
    this.raceAddEntryInfo = null
    this.raceRemoveEntryInfo = null
    this.raceSessionInfo = null
    this.raceSessionStateInfo = null
    this.raceLapInfo = null
    this.raceSplitInfo = null
    this.raceSpeedInfo = null
    this.raceCommunicationInfo = null
    this.raceClassificationInfo = null
    this.raceTrackPositionInfo = null
    this.raceVehicleDataInfo = null

    if (this.isConnected())
      this.disconnect();
  }

  public isConnected(): boolean {
    return addon.isConnected();
  }

  private connect() {
    if (!this.activated) return
    if (this.isConnected()) return

    const isConnected = addon.connect();
    if (isConnected) {
      this.logging && console.log("CONNECTED")
      this.emit('connected')
      this.keepAlive();

      this.updateKartEventInfo()
      this.updateKartSessionInfo()
      this.updateKartLapInfo()
      this.updateKartSplitInfo()
      this.updateKartTelemetryInfo()
      this.updateTrackSegmentInfo()
      this.updateRaceEventInfo()
      this.updateRaceEntriesInfo()
      this.updateRaceAddEntryInfo()
      this.updateRaceRemoveEntryInfo()
      this.updateRaceSessionInfo()
      this.updateRaceSessionStateInfo()
      this.updateRaceLapInfo()
      this.updateRaceSplitInfo()
      this.updateRaceSpeedInfo()
      this.updateRaceCommunicationInfo()
      this.updateRaceClassificationInfo()
      this.updateRaceTrackPositionInfo()
      this.updateRaceVehicleDataInfo()

      return;
    }

    setTimeout(this.connect.bind(this), this.config.Delays.ConnectDelay)
  }

  private disconnect(reason: string = '') {
    addon.disconnect()
    this.logging && console.log("DISCONNECTED")
    this.emit('disconnected', reason)
    if (!this.activated) return
    setTimeout(() => this.connect(), this.config.Delays.ReconnectDelay)
  }

  private async keepAlive() {
    if (!this.activated) return
    if (!this.isConnected()) return

    this.pluginInfo = await addon.listenForPluginInfoPromise();
    this.emit('pluginInfo', this.pluginInfo)
    if (this.pluginInfo.m_iState === -1) {
      this.disconnect();
      return
    }

    if(this.pluginInfo.m_PluginVersion < 6) {
      this.logging && console.error("Plugin version is smaller then 6!")
      this.disconnect("Plugin version is smaller then 6!");
      return
    }

    setTimeout(this.keepAlive.bind(this), this.config.Delays.KeepAliveDelay)
  }

  private async updateKartEventInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.kartEventInfo = await addon.listenForKartEventInfoPromise();
      this.emit('kartEventInfo', this.kartEventInfo)
      setTimeout(this.updateKartEventInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateKartSessionInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.kartSessionInfo = await addon.listenForKartSessionInfoPromise();
      this.emit('kartSessionInfo', this.kartSessionInfo)
      setTimeout(this.updateKartSessionInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateKartLapInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.kartLapInfo = await addon.listenForKartLapInfoPromise();
      this.emit('kartLapInfo', this.kartLapInfo)
      setTimeout(this.updateKartLapInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateKartSplitInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.kartSplitInfo = await addon.listenForKartSplitInfoPromise();
      this.emit('kartSplitInfo', this.kartSplitInfo)
      setTimeout(this.updateKartSplitInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateKartTelemetryInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.kartTelemetryInfo = await addon.listenForKartTelemetryInfoPromise();
      this.emit('kartTelemetryInfo', this.kartTelemetryInfo)
      setTimeout(this.updateKartTelemetryInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateTrackSegmentInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.trackSegmentInfo = await addon.listenForTrackSegmentInfoPromise();
      this.emit('trackSegmentInfo', this.trackSegmentInfo)
      setTimeout(this.updateTrackSegmentInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceEventInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceEventInfo = await addon.listenForRaceEventInfoPromise();
      this.emit('raceEventInfo', this.raceEventInfo)
      setTimeout(this.updateRaceEventInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceEntriesInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceEntriesInfo = await addon.listenForRaceEntriesInfoPromise();
      this.emit('raceEntriesInfo', this.raceEntriesInfo)
      setTimeout(this.updateRaceEntriesInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceAddEntryInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceAddEntryInfo = await addon.listenForRaceAddEntryInfoPromise();
      this.emit('raceAddEntryInfo', this.raceAddEntryInfo)
      setTimeout(this.updateRaceAddEntryInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceRemoveEntryInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceRemoveEntryInfo = await addon.listenForRaceRemoveEntryInfoPromise();
      this.emit('raceRemoveEntryInfo', this.raceRemoveEntryInfo)
      setTimeout(this.updateRaceRemoveEntryInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceSessionInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceSessionInfo = await addon.listenForRaceSessionInfoPromise();
      this.emit('raceSessionInfo', this.raceSessionInfo)
      setTimeout(this.updateRaceSessionInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceSessionStateInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceSessionStateInfo = await addon.listenForRaceSessionStateInfoPromise();
      this.emit('raceSessionStateInfo', this.raceSessionStateInfo)
      setTimeout(this.updateRaceSessionStateInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceLapInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceLapInfo = await addon.listenForRaceLapInfoPromise();
      this.emit('raceLapInfo', this.raceLapInfo)
      setTimeout(this.updateRaceLapInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceSplitInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceSplitInfo = await addon.listenForRaceSplitInfoPromise();
      this.emit('raceSplitInfo', this.raceSplitInfo)
      setTimeout(this.updateRaceSplitInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceSpeedInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceSpeedInfo = await addon.listenForRaceSpeedInfoPromise();
      this.emit('raceSpeedInfo', this.raceSpeedInfo)
      setTimeout(this.updateRaceSpeedInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceCommunicationInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceCommunicationInfo = await addon.listenForRaceCommunicationInfoPromise();
      this.emit('raceCommunicationInfo', this.raceCommunicationInfo)
      setTimeout(this.updateRaceCommunicationInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceClassificationInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceClassificationInfo = await addon.listenForRaceClassificationInfoPromise();
      this.emit('raceClassificationInfo', this.raceClassificationInfo)
      setTimeout(this.updateRaceClassificationInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceTrackPositionInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceTrackPositionInfo = await addon.listenForRaceTrackPositionInfoPromise();
      this.emit('raceTrackPositionInfo', this.raceTrackPositionInfo)
      setTimeout(this.updateRaceTrackPositionInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }

  private async updateRaceVehicleDataInfo() {
    if (!this.activated) return
    if (!this.isConnected()) return

    try {
      this.raceVehicleDataInfo = await addon.listenForRaceVehicleDataInfoPromise();
      this.emit('raceVehicleDataInfo', this.raceVehicleDataInfo)
      setTimeout(this.updateRaceVehicleDataInfo.bind(this), this.config.Delays.UpdateDelay)
    } catch (e) {
      this.logging && console.error(e)
    }
  }
}

export default Wrapper;