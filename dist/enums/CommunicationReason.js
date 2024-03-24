"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.CommunicationReason = void 0;
var CommunicationReason;
(function (CommunicationReason) {
    CommunicationReason[CommunicationReason["JUMP_START"] = 0] = "JUMP_START";
    CommunicationReason[CommunicationReason["HIGH_OFFENCES"] = 1] = "HIGH_OFFENCES";
    CommunicationReason[CommunicationReason["ROLLING_START_SPEEDING"] = 3] = "ROLLING_START_SPEEDING";
    CommunicationReason[CommunicationReason["ROLLING_START_SLOWING"] = 4] = "ROLLING_START_SLOWING";
    CommunicationReason[CommunicationReason["ROLLING_START_CROSSING"] = 5] = "ROLLING_START_CROSSING";
    CommunicationReason[CommunicationReason["ROLLING_START_OVERTAKING"] = 6] = "ROLLING_START_OVERTAKING";
    CommunicationReason[CommunicationReason["DIRECTOR"] = 7] = "DIRECTOR";
})(CommunicationReason || (exports.CommunicationReason = CommunicationReason = {}));
