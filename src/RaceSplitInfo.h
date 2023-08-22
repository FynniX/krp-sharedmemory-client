//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACESPLITINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACESPLITINFO_H

class RaceSplitInfo {
    int lastId = -1;
    MappedBuffer <RaceSplitInfo_t> controller = MappedBuffer<RaceSplitInfo_t>("Local\\KRPSMP_RaceSplitInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceSplitInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACESPLITINFO_H
