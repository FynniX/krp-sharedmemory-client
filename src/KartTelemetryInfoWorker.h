//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTTELEMETRYINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_KARTTELEMETRYINFOWORKER_H

class KartTelemetryInfoWorker : public Napi::AsyncWorker {
    KartTelemetryInfo &info;

public:
    KartTelemetryInfoWorker(Napi::Function &, KartTelemetryInfo &);

    virtual ~KartTelemetryInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTTELEMETRYINFOWORKER_H
