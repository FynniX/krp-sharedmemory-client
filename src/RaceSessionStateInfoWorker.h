//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESESSIONSTATEINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACESESSIONSTATEINFOWORKER_H

class RaceSessionStateInfoWorker : public Napi::AsyncWorker {
    RaceSessionStateInfo &info;

public:
    RaceSessionStateInfoWorker(Napi::Function&, RaceSessionStateInfo&);
    virtual ~RaceSessionStateInfoWorker() {};

    void Execute();
    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESESSIONSTATEINFOWORKER_H
