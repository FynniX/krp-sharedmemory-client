//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESESSIONINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACESESSIONINFO_H

class RaceSessionInfo {
    int lastId = -1;
    MappedBuffer <RaceSessionInfo_t> controller = MappedBuffer<RaceSessionInfo_t>("Local\\KRPSMP_RaceSessionInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceSessionInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESESSIONINFO_H
