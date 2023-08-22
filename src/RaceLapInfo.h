//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACELAPINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACELAPINFO_H

class RaceLapInfo {
    int lastId = -1;
    MappedBuffer <RaceLapInfo_t> controller = MappedBuffer<RaceLapInfo_t>("Local\\KRPSMP_RaceLapInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceLapInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACELAPINFO_H
