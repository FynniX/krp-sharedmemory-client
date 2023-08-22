//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACECOMMUNICATIONINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACECOMMUNICATIONINFO_H

class RaceCommunicationInfo {
    int lastId = -1;
    MappedBuffer <RaceCommunicationInfo_t> controller = MappedBuffer<RaceCommunicationInfo_t>(
            "Local\\KRPSMP_RaceCommunicationInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceCommunicationInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACECOMMUNICATIONINFO_H
