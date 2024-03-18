#ifndef RACELAPSINFO_H
#define RACELAPSINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceLapsInfo : public BaseInfo<RaceLapsInfo_t>
{
public:
    RaceLapsInfo() : BaseInfo<RaceLapsInfo_t>(MB_RACELAPSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif