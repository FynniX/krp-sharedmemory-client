//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACEREMOVEENTRYINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACEREMOVEENTRYINFO_H

class RaceRemoveEntryInfo {
    int lastId = -1;
    MappedBuffer <RaceRemoveEntryInfo_t> controller = MappedBuffer<RaceRemoveEntryInfo_t>(
            "Local\\KRPSMP_RaceRemoveEntryInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceRemoveEntryInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACEREMOVEENTRYINFO_H
