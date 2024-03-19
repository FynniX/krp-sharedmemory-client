import { Addon } from "./interfaces/Addon";

/**
 * @name Addon
 * @description Binding for native addon
 */
// eslint-disable-next-line @typescript-eslint/no-var-requires
export const addon: Addon = require("../build/Release/krp-sharedmemory-client-native");
