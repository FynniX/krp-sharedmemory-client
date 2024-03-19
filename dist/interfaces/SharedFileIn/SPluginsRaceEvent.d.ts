import { EventType } from "../../enums/EventType";
export interface SPluginsRaceEvent {
    m_iType: EventType;
    m_szName: string;
    m_szTrackName: string;
    m_fTrackLength: number;
}
