//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_KARTTELEMETRYINFO_H
#define KRP_SHAREDMEMORY_CLIENT_KARTTELEMETRYINFO_H

class KartTelemetryInfo {
    int lastId = -1;
    MappedBuffer <KartTelemetryInfo_t> controller = MappedBuffer<KartTelemetryInfo_t>(
            "Local\\KRPSMP_KartTelemetryInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    KartTelemetryInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_KARTTELEMETRYINFO_H
