//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESPEEDINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACESPEEDINFO_H

class RaceSpeedInfo {
    int lastId = -1;
    MappedBuffer <RaceSpeedInfo_t> controller = MappedBuffer<RaceSpeedInfo_t>("Local\\KRPSMP_RaceSpeedInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceSpeedInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESPEEDINFO_H
