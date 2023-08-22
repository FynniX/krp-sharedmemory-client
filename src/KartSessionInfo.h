//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTSESSIONINFO_H
#define KRP_SHAREDMEMORY_CLIENT_KARTSESSIONINFO_H

class KartSessionInfo {
    int lastId = -1;
    MappedBuffer <KartSessionInfo_t> controller = MappedBuffer<KartSessionInfo_t>("Local\\KRPSMP_KartSessionInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    KartSessionInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTSESSIONINFO_H
