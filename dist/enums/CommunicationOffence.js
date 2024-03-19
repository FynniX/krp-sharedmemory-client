"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.CommunicationOffence = void 0;
var CommunicationOffence;
(function (CommunicationOffence) {
  CommunicationOffence[(CommunicationOffence["JUMP_START"] = 1)] = "JUMP_START";
  CommunicationOffence[(CommunicationOffence["CUTTING"] = 3)] = "CUTTING";
  CommunicationOffence[(CommunicationOffence["ROLLING_START_SPEEDING"] = 4)] =
    "ROLLING_START_SPEEDING";
  CommunicationOffence[(CommunicationOffence["ROLLING_START_SLOWING"] = 5)] =
    "ROLLING_START_SLOWING";
  CommunicationOffence[(CommunicationOffence["ROLLING_START_CROSSING"] = 6)] =
    "ROLLING_START_CROSSING";
  CommunicationOffence[(CommunicationOffence["ROLLING_START_OVERTAKING"] = 7)] =
    "ROLLING_START_OVERTAKING";
})(
  CommunicationOffence ||
    (exports.CommunicationOffence = CommunicationOffence = {}),
);
