#ifndef CAMERASINFO_H
#define CAMERASINFO_H

#include "../BaseInfo/BaseInfo.h"

class CamerasInfo : public BaseInfo<CamerasInfo_t>
{
public:
    CamerasInfo() : BaseInfo<CamerasInfo_t>(MB_CAMERASINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif