//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEEVENTINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACEEVENTINFOWORKER_H

class RaceEventInfoWorker : public Napi::AsyncWorker {
    RaceEventInfo &info;

public:
    RaceEventInfoWorker(Napi::Function &, RaceEventInfo &);

    virtual ~RaceEventInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEEVENTINFOWORKER_H
