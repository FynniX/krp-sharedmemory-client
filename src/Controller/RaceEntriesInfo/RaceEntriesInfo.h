#ifndef RACEENTRIESINFO_H
#define RACEENTRIESINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceEntriesInfo : public BaseInfo<RaceEntriesInfo_t>
{
public:
    RaceEntriesInfo() : BaseInfo<RaceEntriesInfo_t>(MB_RACEENTRIESINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif