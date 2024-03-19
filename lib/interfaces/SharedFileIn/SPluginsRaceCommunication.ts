import { CommunicationOffence } from "../../enums/CommunicationOffence";
import { CommunicationOffenceType } from "../../enums/CommunicationOffenceType";
import { CommunicationReason } from "../../enums/CommunicationReason";
import { CommunicationType } from "../../enums/CommunicationType";
import { EntryState } from "../../enums/EntryState";
import { PractiseSessionType } from "../../enums/PractiseSessionType";
import { RaceSessionType } from "../../enums/RaceSessionType";

export interface SPluginsRaceCommunication {
  m_iSession: 0 | PractiseSessionType | RaceSessionType;
  m_iSessionSeries: number;
  m_iRaceNum: number;
  m_iCommunication: CommunicationType;
  m_iState: EntryState;
  m_iReason: CommunicationReason;
  m_iOffence: CommunicationOffence;
  m_iLap: number;
  m_iType: CommunicationOffenceType;
  m_iTime: number;
}
