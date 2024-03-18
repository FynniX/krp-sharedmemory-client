#ifndef KARTEVENTINFO_H
#define KARTEVENTINFO_H

#include "../BaseInfo/BaseInfo.h"

class KartEventInfo : public BaseInfo<KartEventInfo_t>
{
public:
    KartEventInfo() : BaseInfo<KartEventInfo_t>(MB_KARTEVENTINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif