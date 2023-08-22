//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTSPLITINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_KARTSPLITINFOWORKER_H

class KartSplitInfoWorker : public Napi::AsyncWorker {
    KartSplitInfo &info;

public:
    KartSplitInfoWorker(Napi::Function &, KartSplitInfo &);

    virtual ~KartSplitInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTSPLITINFOWORKER_H
