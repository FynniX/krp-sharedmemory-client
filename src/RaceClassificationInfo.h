//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACECLASSIFICATIONINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACECLASSIFICATIONINFO_H

class RaceClassificationInfo {
    int lastId = -1;
    MappedBuffer <RaceClassificationInfo_t> controller = MappedBuffer<RaceClassificationInfo_t>(
            "Local\\KRPSMP_RaceClassificationInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceClassificationInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACECLASSIFICATIONINFO_H
