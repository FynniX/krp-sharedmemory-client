//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESPEEDINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACESPEEDINFOWORKER_H

class RaceSpeedInfoWorker : public Napi::AsyncWorker {
    RaceSpeedInfo &info;

public:
    RaceSpeedInfoWorker(Napi::Function &, RaceSpeedInfo &);

    virtual ~RaceSpeedInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESPEEDINFOWORKER_H
