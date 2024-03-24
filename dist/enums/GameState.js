export var GameState;
(function (GameState) {
    GameState[GameState["MENU"] = 0] = "MENU";
    GameState[GameState["PAUSED"] = 1] = "PAUSED";
    GameState[GameState["RUNNING"] = 2] = "RUNNING";
    GameState[GameState["CLOSED"] = -1] = "CLOSED";
})(GameState || (GameState = {}));
