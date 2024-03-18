#ifndef RACEVEHICLESDATAINFO_H
#define RACEVEHICLESDATAINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceVehiclesDataInfo : public BaseInfo<RaceVehiclesDataInfo_t>
{
public:
    RaceVehiclesDataInfo() : BaseInfo<RaceVehiclesDataInfo_t>(MB_RACEVEHICLESDATAINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif