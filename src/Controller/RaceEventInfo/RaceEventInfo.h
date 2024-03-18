#ifndef RACEEVENTINFO_H
#define RACEEVENTINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceEventInfo : public BaseInfo<RaceEventInfo_t>
{
public:
    RaceEventInfo() : BaseInfo<RaceEventInfo_t>(MB_RACEEVENTINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif