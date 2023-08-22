//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_RACETRACKPOSITIONINFO_H
#define KRP_SHAREDMEMORY_CLIENT_RACETRACKPOSITIONINFO_H

class RaceTrackPositionInfo {
    int lastId = -1;
    MappedBuffer <RaceTrackPositionInfo_t> controller = MappedBuffer<RaceTrackPositionInfo_t>(
            "Local\\KRPSMP_RaceTrackPositionInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    RaceTrackPositionInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_RACETRACKPOSITIONINFO_H
