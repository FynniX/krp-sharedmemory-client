//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESESSIONINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACESESSIONINFOWORKER_H

class RaceSessionInfoWorker : public Napi::AsyncWorker {
    RaceSessionInfo &info;

public:
    RaceSessionInfoWorker(Napi::Function &, RaceSessionInfo &);

    virtual ~RaceSessionInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESESSIONINFOWORKER_H
