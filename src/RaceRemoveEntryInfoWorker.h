//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEREMOVEENTRYINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACEREMOVEENTRYINFOWORKER_H

class RaceRemoveEntryInfoWorker : public Napi::AsyncWorker {
    RaceRemoveEntryInfo &info;

public:
    RaceRemoveEntryInfoWorker(Napi::Function&, RaceRemoveEntryInfo&);
    virtual ~RaceRemoveEntryInfoWorker() {};

    void Execute();
    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEREMOVEENTRYINFOWORKER_H
