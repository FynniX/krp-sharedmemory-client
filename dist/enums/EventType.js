"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.EventType = void 0;
var EventType;
(function (EventType) {
    EventType[EventType["REPLAY"] = -1] = "REPLAY";
    EventType[EventType["TESTING"] = 1] = "TESTING";
    EventType[EventType["RACE"] = 2] = "RACE";
    EventType[EventType["CHALLENGE"] = 4] = "CHALLENGE";
})(EventType || (exports.EventType = EventType = {}));
