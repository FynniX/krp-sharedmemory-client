//
// Created by Fynn Haupt on 02.11.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_CAMERAINFO_H
#define KRP_SHAREDMEMORY_CLIENT_CAMERAINFO_H

class CameraInfo {
    int lastId = -1;
    MappedBuffer <CameraInfo_t> controller = MappedBuffer<CameraInfo_t>("Local\\KRPSMP_CameraInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    CameraInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_CAMERAINFO_H