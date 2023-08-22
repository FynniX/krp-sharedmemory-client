//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTEVENTINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_KARTEVENTINFOWORKER_H

class KartEventInfoWorker : public Napi::AsyncWorker {
    KartEventInfo &info;

public:
    KartEventInfoWorker(Napi::Function &, KartEventInfo &);

    virtual ~KartEventInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTEVENTINFOWORKER_H
