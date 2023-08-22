//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACETRACKPOSITIONINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACETRACKPOSITIONINFOWORKER_H

class RaceTrackPositionInfoWorker : public Napi::AsyncWorker {
    RaceTrackPositionInfo &info;

public:
    RaceTrackPositionInfoWorker(Napi::Function&, RaceTrackPositionInfo&);
    virtual ~RaceTrackPositionInfoWorker() {};

    void Execute();
    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACETRACKPOSITIONINFOWORKER_H
