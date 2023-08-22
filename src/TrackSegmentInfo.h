//
// Created by Fynn Haupt on 18.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_TRACKSEGMENTINFO_H
#define KRP_SHAREDMEMORY_CLIENT_TRACKSEGMENTINFO_H

class TrackSegmentInfo {
    int lastId = -1;
    MappedBuffer <TrackSegmentInfo_t> controller = MappedBuffer<TrackSegmentInfo_t>("Local\\KRPSMP_TrackSegmentInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    TrackSegmentInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_TRACKSEGMENTINFO_H
