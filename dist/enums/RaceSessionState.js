"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.RaceSessionState = void 0;
var RaceSessionState;
(function (RaceSessionState) {
  RaceSessionState[(RaceSessionState["RUNNING"] = 16)] = "RUNNING";
  RaceSessionState[(RaceSessionState["SEMAPHORE"] = 32)] = "SEMAPHORE";
  RaceSessionState[(RaceSessionState["SIGHTING_LAP"] = 64)] = "SIGHTING_LAP";
  RaceSessionState[(RaceSessionState["WARMUP_LAP"] = 128)] = "WARMUP_LAP";
  RaceSessionState[(RaceSessionState["PRESTART"] = 256)] = "PRESTART";
  RaceSessionState[(RaceSessionState["RACEOVER"] = 512)] = "RACEOVER";
  RaceSessionState[(RaceSessionState["COMPLETED"] = 1024)] = "COMPLETED";
  RaceSessionState[(RaceSessionState["ROLLING_START"] = 2048)] =
    "ROLLING_START";
})(RaceSessionState || (exports.RaceSessionState = RaceSessionState = {}));
