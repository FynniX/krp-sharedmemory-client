//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACELAPINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACELAPINFOWORKER_H

class RaceLapInfoWorker : public Napi::AsyncWorker {
    RaceLapInfo &info;

public:
    RaceLapInfoWorker(Napi::Function &, RaceLapInfo &);

    virtual ~RaceLapInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACELAPINFOWORKER_H
