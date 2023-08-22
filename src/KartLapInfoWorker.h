//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTLAPINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_KARTLAPINFOWORKER_H

class KartLapInfoWorker : public Napi::AsyncWorker {
    KartLapInfo &info;

public:
    KartLapInfoWorker(Napi::Function &, KartLapInfo &);

    virtual ~KartLapInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTLAPINFOWORKER_H
