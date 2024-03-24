export var RaceSessionType;
(function (RaceSessionType) {
    RaceSessionType[RaceSessionType["WAITING"] = 0] = "WAITING";
    RaceSessionType[RaceSessionType["PRACTISE"] = 1] = "PRACTISE";
    RaceSessionType[RaceSessionType["QUALIFY"] = 2] = "QUALIFY";
    RaceSessionType[RaceSessionType["WARMUP"] = 3] = "WARMUP";
    RaceSessionType[RaceSessionType["HEAT"] = 4] = "HEAT";
    RaceSessionType[RaceSessionType["SECOND_CHANCE"] = 5] = "SECOND_CHANCE";
    RaceSessionType[RaceSessionType["PREFINAL"] = 6] = "PREFINAL";
    RaceSessionType[RaceSessionType["FINAL"] = 7] = "FINAL";
})(RaceSessionType || (RaceSessionType = {}));
