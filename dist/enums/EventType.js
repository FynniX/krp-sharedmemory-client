export var EventType;
(function (EventType) {
    EventType[EventType["REPLAY"] = -1] = "REPLAY";
    EventType[EventType["TESTING"] = 1] = "TESTING";
    EventType[EventType["RACE"] = 2] = "RACE";
    EventType[EventType["CHALLENGE"] = 4] = "CHALLENGE";
})(EventType || (EventType = {}));
