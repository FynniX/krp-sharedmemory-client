//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEVEHICLEDATAINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_RACEVEHICLEDATAINFOWORKER_H

class RaceVehicleDataInfoWorker : public Napi::AsyncWorker {
    RaceVehicleDataInfo &info;

public:
    RaceVehicleDataInfoWorker(Napi::Function&, RaceVehicleDataInfo&);
    virtual ~RaceVehicleDataInfoWorker() {};

    void Execute();
    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEVEHICLEDATAINFOWORKER_H
