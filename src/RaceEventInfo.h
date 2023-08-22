//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEEVENTINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACEEVENTINFO_H

class RaceEventInfo {
    int lastId = -1;
    MappedBuffer <RaceEventInfo_t> controller = MappedBuffer<RaceEventInfo_t>("Local\\KRPSMP_RaceEventInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceEventInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEEVENTINFO_H
