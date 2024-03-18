#ifndef RACESPLITSINFO_H
#define RACESPLITSINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceSplitsInfo : public BaseInfo<RaceSplitsInfo_t>
{
public:
    RaceSplitsInfo() : BaseInfo<RaceSplitsInfo_t>(MB_RACESPLITSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif