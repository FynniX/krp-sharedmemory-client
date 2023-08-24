const addon = require("../dist/binding.js");
const assert = require("assert");

assert(addon.connect, "Connect function is undefined");
assert(addon.disconnect, "Disconnect function is undefined");
assert(addon.isConnected, "isConnected function is undefined");
assert(addon.listenForPluginInfo, "listenForPluginInfo function is undefined");
assert(addon.listenForPluginInfoPromise, "listenForPluginInfoPromise function is undefined");
assert(addon.listenForKartEventInfo, "listenForKartEventInfo function is undefined");
assert(addon.listenForKartEventInfoPromise, "listenForKartEventInfoPromise function is undefined");
assert(addon.listenForKartSessionInfo, "listenForKartSessionInfo function is undefined");
assert(addon.listenForKartSessionInfoPromise, "listenForKartSessionInfoPromise function is undefined");
assert(addon.listenForKartLapInfo, "listenForKartLapInfo function is undefined");
assert(addon.listenForKartLapInfoPromise, "listenForKartLapInfoPromise function is undefined");
assert(addon.listenForKartSplitInfo, "listenForKartSplitInfo function is undefined");
assert(addon.listenForKartSplitInfoPromise, "listenForKartSplitInfoPromise function is undefined");
assert(addon.listenForKartTelemetryInfo, "listenForKartTelemetryInfo function is undefined");
assert(addon.listenForKartTelemetryInfoPromise, "listenForKartTelemetryInfoPromise function is undefined");
assert(addon.listenForTrackSegmentInfo, "listenForTrackSegmentInfo function is undefined");
assert(addon.listenForTrackSegmentInfoPromise, "listenForTrackSegmentInfoPromise function is undefined");
assert(addon.listenForRaceEventInfo, "listenForRaceEventInfo function is undefined");
assert(addon.listenForRaceEventInfoPromise, "listenForRaceEventInfoPromise function is undefined");
assert(addon.listenForRaceEntriesInfo, "listenForRaceEntriesInfo function is undefined");
assert(addon.listenForRaceEntriesInfoPromise, "listenForRaceEntriesInfoPromise function is undefined");
assert(addon.listenForRaceAddEntryInfo, "listenForRaceAddEntryInfo function is undefined");
assert(addon.listenForRaceAddEntryInfoPromise, "listenForRaceAddEntryInfoPromise function is undefined");
assert(addon.listenForRaceRemoveEntryInfo, "listenForRaceRemoveEntryInfo function is undefined");
assert(addon.listenForRaceRemoveEntryInfoPromise, "listenForRaceRemoveEntryInfoPromise function is undefined");
assert(addon.listenForRaceSessionInfo, "listenForRaceSessionInfo function is undefined");
assert(addon.listenForRaceSessionInfoPromise, "listenForRaceSessionInfoPromise function is undefined");
assert(addon.listenForRaceSessionStateInfo, "listenForRaceSessionStateInfo function is undefined");
assert(addon.listenForRaceSessionStateInfoPromise, "listenForRaceSessionStateInfoPromise function is undefined");
assert(addon.listenForRaceLapInfo, "listenForRaceLapInfo function is undefined");
assert(addon.listenForRaceLapInfoPromise, "listenForRaceLapInfoPromise function is undefined");
assert(addon.listenForRaceSplitInfo, "listenForRaceSplitInfo function is undefined");
assert(addon.listenForRaceSplitInfoPromise, "listenForRaceSplitInfoPromise function is undefined");
assert(addon.listenForRaceSpeedInfo, "listenForRaceSpeedInfo function is undefined");
assert(addon.listenForRaceSpeedInfoPromise, "listenForRaceSpeedInfoPromise function is undefined");
assert(addon.listenForRaceCommunicationInfo, "listenForRaceCommunicationInfo function is undefined");
assert(addon.listenForRaceCommunicationInfoPromise, "listenForRaceCommunicationInfoPromise function is undefined");
assert(addon.listenForRaceClassificationInfo, "listenForRaceClassificationInfo function is undefined");
assert(addon.listenForRaceClassificationInfoPromise, "listenForRaceClassificationInfoPromise function is undefined");
assert(addon.listenForRaceTrackPositionInfo, "listenForRaceTrackPositionInfo function is undefined");
assert(addon.listenForRaceTrackPositionInfoPromise, "listenForRaceTrackPositionInfoPromise function is undefined");
assert(addon.listenForRaceVehicleDataInfo, "listenForRaceVehicleDataInfo function is undefined");
assert(addon.listenForRaceVehicleDataInfoPromise, "listenForRaceVehicleDataInfoPromise function is undefined");

async function tests() {
    const isConnectedResult1 = addon.isConnected();
    assert.strictEqual(isConnectedResult1, false, "isConnected function failed!");

    await assert.strict.rejects(addon.listenForPluginInfoPromise)

    const connectResult = addon.connect();
    assert.strictEqual(connectResult, true, "Connect function failed! Kart racing pro needs to be started!");

    const isConnectedResult2 = addon.isConnected();
    assert.strictEqual(isConnectedResult2, true, "isConnected function failed!");

    const listenForPluginInfoPromiseResult = await addon.listenForPluginInfoPromise();
    assert.notStrictEqual(listenForPluginInfoPromiseResult.m_id, undefined, "PluginInfo m_id is undefined!");
    assert.strictEqual(listenForPluginInfoPromiseResult.m_id, 0, "PluginInfo m_id is not 0!")

    console.log("Please close kart racing pro now!")
    const listenForPluginInfoPromiseResult1 = await addon.listenForPluginInfoPromise();
    assert.notStrictEqual(listenForPluginInfoPromiseResult1.m_id, undefined, "PluginInfo m_id is undefined!");
    assert.strictEqual(listenForPluginInfoPromiseResult1.m_id, 1, "PluginInfo m_id is not 1!")

    const disconnectResult = addon.disconnect();
    assert.strictEqual(disconnectResult, null, "Disconnect function failed!");

    console.log("Tests passed - everything looks OK!");
}

assert.doesNotThrow(tests, undefined, "Tests failed:");