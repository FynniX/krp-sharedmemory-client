const wrapper = require("../dist/wrapper.js");

const krp = new wrapper.default(false, {
  Delays: {
    ConnectDelay: 0,
    ReconnectDelay: 5000,
    KeepAliveDelay: 0,
    UpdateDelay: 0,
    WaitDelay: 10,
  },
});
