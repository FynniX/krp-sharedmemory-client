//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTLAPINFO_H
#define KRP_SHAREDMEMORY_CLIENT_KARTLAPINFO_H

class KartLapInfo {
    int lastId = -1;
    MappedBuffer <KartLapInfo_t> controller = MappedBuffer<KartLapInfo_t>("Local\\KRPSMP_KartLapInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    KartLapInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTLAPINFO_H
