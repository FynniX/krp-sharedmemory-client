#ifndef RACESPEEDSINFO_H
#define RACESPEEDSINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceSpeedsInfo : public BaseInfo<RaceSpeedsInfo_t>
{
public:
    RaceSpeedsInfo() : BaseInfo<RaceSpeedsInfo_t>(MB_RACESPEEDSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif