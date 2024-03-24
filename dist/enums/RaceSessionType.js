"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.RaceSessionType = void 0;
var RaceSessionType;
(function (RaceSessionType) {
    RaceSessionType[RaceSessionType["WAITING"] = 0] = "WAITING";
    RaceSessionType[RaceSessionType["PRACTISE"] = 1] = "PRACTISE";
    RaceSessionType[RaceSessionType["QUALIFY"] = 2] = "QUALIFY";
    RaceSessionType[RaceSessionType["WARMUP"] = 3] = "WARMUP";
    RaceSessionType[RaceSessionType["HEAT"] = 4] = "HEAT";
    RaceSessionType[RaceSessionType["SECOND_CHANCE"] = 5] = "SECOND_CHANCE";
    RaceSessionType[RaceSessionType["PREFINAL"] = 6] = "PREFINAL";
    RaceSessionType[RaceSessionType["FINAL"] = 7] = "FINAL";
})(RaceSessionType || (exports.RaceSessionType = RaceSessionType = {}));
