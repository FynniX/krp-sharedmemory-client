#ifndef CAMERASCONTROLINFO_H
#define CAMERASCONTROLINFO_H

#include "../BaseInfo/BaseInfo.h"

class CamerasControlInfo : public BaseInfo<CamerasControlInfo_t>
{
public:
    CamerasControlInfo() : BaseInfo<CamerasControlInfo_t>(MB_CAMERASCONTROLINFO_FILE_NAME) {}
    void SetVehicle(int vehicle);
    void SetCamera(int camera);
};

#endif