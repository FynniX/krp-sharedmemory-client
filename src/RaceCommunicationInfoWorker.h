//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACECOMMUNICATIONINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACECOMMUNICATIONINFOWORKER_H

class RaceCommunicationInfoWorker : public Napi::AsyncWorker {
    RaceCommunicationInfo &info;

public:
    RaceCommunicationInfoWorker(Napi::Function&, RaceCommunicationInfo&);
    virtual ~RaceCommunicationInfoWorker() {};

    void Execute();
    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACECOMMUNICATIONINFOWORKER_H
