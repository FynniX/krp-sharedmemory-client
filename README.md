# krp-sharedmemory-client

Node.js Wrapper to communicate with [Kart Racing Pro](https://www.kartracing-pro.com/) Client.

**_krp-sharedmemory-client_** is the client for the **_krp-sharedmemory-plugin_**.

## Requirements

- [krp-sharedmemory-plugin](https://github.com/FynniX/krp-sharedmemory-plugin)

## Installing

This package was tested under [Node.js](https://nodejs.org/) 18.17.0 x64.

[Kart Racing Pro](https://www.kartracing-pro.com/) release13e was used while testing.

`npm install krp-sharedmemory-client`

## Documentation

[Documentation](https://fynnix.github.io/krp-sharedmemory-client/)

### Events

| Event          | Description                 |
| -------------- | --------------------------- |
| "connected"    | Shared Memory connected.    |
| "disconnected" | Shared Memory disconnected. |
| "pluginInfo"   | pluginInfo updated.         |
| "...Info"      | ...Info updated.            |

#### Example

```js
const wrapper = new Wrapper(Config);

wrapper.on("connected", () => {
  console.log("Connected!");
});
```

## License

Released under the [MIT License](https://github.com/FynniX/krp-sharedmemory-client/blob/main/License).
