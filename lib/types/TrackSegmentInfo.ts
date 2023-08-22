import {SPluginsTrackSegment} from './SPluginsTrackSegment'

export type TrackSegmentInfo = {
  m_id: number;
  _iNumSegments: number;
  m_TrackSegments: SPluginsTrackSegment[];
  m_RaceData: number[];
}