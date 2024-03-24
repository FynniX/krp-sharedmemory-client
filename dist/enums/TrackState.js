"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.TrackState = void 0;
var TrackState;
(function (TrackState) {
    TrackState[TrackState["ONTRACK"] = 0] = "ONTRACK";
    TrackState[TrackState["SPECTATE"] = 1] = "SPECTATE";
    TrackState[TrackState["REPLAY"] = 2] = "REPLAY";
})(TrackState || (exports.TrackState = TrackState = {}));
