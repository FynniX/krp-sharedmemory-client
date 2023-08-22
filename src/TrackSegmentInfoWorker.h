//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_TRACKSEGMENTINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_TRACKSEGMENTINFOWORKER_H

class TrackSegmentInfoWorker : public Napi::AsyncWorker {
    TrackSegmentInfo &info;

public:
    TrackSegmentInfoWorker(Napi::Function &, TrackSegmentInfo &);

    virtual ~TrackSegmentInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_TRACKSEGMENTINFOWORKER_H
