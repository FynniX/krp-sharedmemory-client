import { SPluginsTrackSegment } from "../SharedFileIn/SPluginsTrackSegment";
import { BaseInfo } from "./BaseInfo";

export interface TrackSegmentsInfo extends BaseInfo {
  _iNumSegments: number;
  m_TrackSegments: SPluginsTrackSegment[];
  m_RaceData: number[];
}
