//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTSPLITINFO_H
#define KRP_SHAREDMEMORY_CLIENT_KARTSPLITINFO_H

class KartSplitInfo {
    int lastId = -1;
    MappedBuffer <KartSplitInfo_t> controller = MappedBuffer<KartSplitInfo_t>("Local\\KRPSMP_KartSplitInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    KartSplitInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTSPLITINFO_H
