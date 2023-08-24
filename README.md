# krp-sharedmemory-client

Node.js Wrapper to communicate with [Kart Racing Pro](https://www.kartracing-pro.com/) Client.

***krp-sharedmemory-client*** is the client for the ***krp-sharedmemory-plugin***.

## Requirements

- [krp-sharedmemory-plugin](https://github.com/FynniX/krp-sharedmemory-plugin)
- Environmental Variable **UV_THREADPOOL_SIZE** needs to be higher than 20!

## Installing

This package was tested under [Node.js](https://nodejs.org/) 18.17.0 x64.

[Kart Racing Pro](https://www.kartracing-pro.com/) release13b was used while testing.

`npm install krp-sharedmemory-client`

## API documentation

## Types

Under src/types/

```
PluginInfo
KartEventInfo
KartSessionInfo
KartLapInfo
KartSplitInfo
KartTelemetryInfo
TrackSegmentInfo
RaceEventInfo
RaceAddEntryInfo
RaceRemoveEntryInfo
RaceSessionInfo
RaceSessionStateInfo
RaceLapInfo
RaceSplitInfo
RaceSpeedInfo
RaceCommunicationInfo
RaceClassificationInfo
RaceTrackPositionInfo
RaceVehicleDataInfo
```

# Wrapper

## Examples

```js
const wrapper = new Wrapper(Logging, Config)
```

| Event          | Description                 |
|----------------|-----------------------------|
| "connected"    | Shared Memory connected.    |
| "disconnected" | Shared Memory disconnected. |
| "pluginInfo"   | pluginInfo updated.         |
| "...Info"      | ...Info updated.            |

```js
wrapper.on("connected", () => {
  console.log("Connected!")
})
```

```js
wrapper.on("pluginInfo", (pluginInfo) => {
  console.log(pluginInfo)
})
```

| Function / Attribute | Description          |
|----------------------|----------------------|
| isConnected          | Is client connected? |
| pluginInfo           | current pluginInfo   |
| ...Info              | current ...Info      |

```js
wrapper.isConnected()
```

## License

Released under the [MIT License](https://github.com/FynniX/krp-sharedmemory-client/blob/main/LICENSE).
