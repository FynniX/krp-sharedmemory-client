//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESESSIONSTATEINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACESESSIONSTATEINFO_H

class RaceSessionStateInfo {
    int lastId = -1;
    MappedBuffer <RaceSessionStateInfo_t> controller = MappedBuffer<RaceSessionStateInfo_t>(
            "Local\\KRPSMP_RaceSessionStateInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceSessionStateInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESESSIONSTATEINFO_H
