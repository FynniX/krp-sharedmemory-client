//
// Created by Fynn Haupt on 02.11.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_CAMERASET_H
#define KRP_SHAREDMEMORY_CLIENT_CAMERASET_H

class CameraSet {
    MappedBuffer <CameraSet_t> controller = MappedBuffer<CameraSet_t>("Local\\KRPSMP_CameraSet");
public:
    bool isConnected = false;

    void connect();

    void setIsControlled(int isControlled);
    void setSelectedVehicle(int selectedVehicle);
    void setSelectedCamera(int selectedCamera);

    void disconnect();
};

#endif //KRP_SHAREDMEMORY_CLIENT_CAMERASET_H