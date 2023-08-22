//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACECLASSIFICATIONINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACECLASSIFICATIONINFOWORKER_H

class RaceClassificationInfoWorker : public Napi::AsyncWorker {
    RaceClassificationInfo &info;

public:
    RaceClassificationInfoWorker(Napi::Function&, RaceClassificationInfo&);
    virtual ~RaceClassificationInfoWorker() {};

    void Execute();
    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACECLASSIFICATIONINFOWORKER_H
