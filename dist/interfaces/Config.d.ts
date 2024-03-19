import { ConfigDelay } from "../enums/ConfigDelay";
export interface Config {
    ConnectDelay: ConfigDelay;
    ReconnectDelay: ConfigDelay;
    KeepAliveDelay: ConfigDelay;
    UpdateDelay: ConfigDelay;
    logging: boolean;
}
