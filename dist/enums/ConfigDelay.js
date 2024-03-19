"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ConfigDelay = void 0;
var ConfigDelay;
(function (ConfigDelay) {
    ConfigDelay[ConfigDelay["SLOWEST"] = 5000] = "SLOWEST";
    ConfigDelay[ConfigDelay["SLOW"] = 1000] = "SLOW";
    ConfigDelay[ConfigDelay["NORMAL"] = 100] = "NORMAL";
    ConfigDelay[ConfigDelay["FAST"] = 10] = "FAST";
    ConfigDelay[ConfigDelay["FASTEST"] = 1] = "FASTEST";
})(ConfigDelay || (exports.ConfigDelay = ConfigDelay = {}));
