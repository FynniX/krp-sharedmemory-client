//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEADDENTRYINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACEADDENTRYINFOWORKER_H

class RaceAddEntryInfoWorker : public Napi::AsyncWorker {
    RaceAddEntryInfo &info;

public:
    RaceAddEntryInfoWorker(Napi::Function &, RaceAddEntryInfo &);

    virtual ~RaceAddEntryInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEADDENTRYINFOWORKER_H
