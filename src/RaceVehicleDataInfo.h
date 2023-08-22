//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEVEHICLEDATAINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACEVEHICLEDATAINFO_H

class RaceVehicleDataInfo {
    int lastId = -1;
    MappedBuffer <RaceVehicleDataInfo_t> controller = MappedBuffer<RaceVehicleDataInfo_t>(
            "Local\\KRPSMP_RaceVehicleDataInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceVehicleDataInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEVEHICLEDATAINFO_H
