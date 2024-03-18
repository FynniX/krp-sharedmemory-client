#ifndef KARTLAPSINFO_H
#define KARTLAPSINFO_H

#include "../BaseInfo/BaseInfo.h"

class KartLapsInfo : public BaseInfo<KartLapsInfo_t>
{
public:
    KartLapsInfo() : BaseInfo<KartLapsInfo_t>(MB_KARTLAPSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif