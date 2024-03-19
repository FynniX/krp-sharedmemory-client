"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.GameState = void 0;
var GameState;
(function (GameState) {
    GameState[GameState["MENU"] = 0] = "MENU";
    GameState[GameState["PAUSED"] = 1] = "PAUSED";
    GameState[GameState["RUNNING"] = 2] = "RUNNING";
    GameState[GameState["CLOSED"] = -1] = "CLOSED";
})(GameState || (exports.GameState = GameState = {}));
