#ifndef RACESESSIONINFO_H
#define RACESESSIONINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceSessionInfo : public BaseInfo<RaceSessionInfo_t>
{
public:
    RaceSessionInfo() : BaseInfo<RaceSessionInfo_t>(MB_RACESESSIONINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif