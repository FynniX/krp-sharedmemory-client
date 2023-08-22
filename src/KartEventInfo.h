//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTEVENTINFO_H
#define KRP_SHAREDMEMORY_CLIENT_KARTEVENTINFO_H

class KartEventInfo {
    int lastId = -1;
    MappedBuffer <KartEventInfo_t> controller = MappedBuffer<KartEventInfo_t>("Local\\KRPSMP_KartEventInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    KartEventInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTEVENTINFO_H
