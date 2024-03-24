"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.addon = void 0;
const krp_sharedmemory_client_native_node_1 = __importDefault(require("../krp-sharedmemory-client-native.node"));
/**
 * @name Addon
 * @description Binding for native addon
 */
// eslint-disable-next-line @typescript-eslint/no-var-requires
exports.addon = krp_sharedmemory_client_native_node_1.default;
