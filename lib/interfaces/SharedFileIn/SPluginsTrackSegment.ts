import { TrackSegmentType } from "../../enums/TrackSegmentType";

export interface SPluginsTrackSegment {
  m_iType: TrackSegmentType;
  m_fLength: number;
  m_fRadius: number;
  m_fAngle: number;
  m_afStart: number[];
  m_fHeight: number;
}
