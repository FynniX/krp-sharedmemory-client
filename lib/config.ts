export type Config = {
  Delays: { ConnectDelay: number, KeepAliveDelay: number, UpdateDelay: number, WaitDelay: number }
}

export const DefaultConfig: Config = {
  Delays: {
    ConnectDelay: 0,
    KeepAliveDelay: 0,
    UpdateDelay: 0,
    WaitDelay: 1000,
  }
}