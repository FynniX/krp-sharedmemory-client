//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESPLITINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACESPLITINFOWORKER_H

class RaceSplitInfoWorker : public Napi::AsyncWorker {
    RaceSplitInfo &info;

public:
    RaceSplitInfoWorker(Napi::Function &, RaceSplitInfo &);

    virtual ~RaceSplitInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESPLITINFOWORKER_H
