//
// Created by Fynn Haupt on 24.08.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEENTRIESINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACEENTRIESINFO_H


class RaceEntriesInfo {
    int lastId = -1;
    MappedBuffer <RaceEntriesInfo_t> controller = MappedBuffer<RaceEntriesInfo_t>("Local\\KRPSMP_RaceEntriesInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceEntriesInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEENTRIESINFO_H
