//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTSESSIONINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_KARTSESSIONINFOWORKER_H

class KartSessionInfoWorker : public Napi::AsyncWorker {
    KartSessionInfo &info;

public:
    KartSessionInfoWorker(Napi::Function &, KartSessionInfo &);

    virtual ~KartSessionInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTSESSIONINFOWORKER_H
