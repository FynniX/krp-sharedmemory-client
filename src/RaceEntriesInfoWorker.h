//
// Created by Fynn Haupt on 24.08.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEENTRIESINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACEENTRIESINFOWORKER_H


class RaceEntriesInfoWorker : public Napi::AsyncWorker {
    RaceEntriesInfo &info;

public:
    RaceEntriesInfoWorker(Napi::Function &, RaceEntriesInfo &);

    virtual ~RaceEntriesInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEENTRIESINFOWORKER_H
