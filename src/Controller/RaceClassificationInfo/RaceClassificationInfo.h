#ifndef RACECLASSIFICATIONINFO_H
#define RACECLASSIFICATIONINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceClassificationInfo : public BaseInfo<RaceClassificationInfo_t>
{
public:
    RaceClassificationInfo() : BaseInfo<RaceClassificationInfo_t>(MB_RACECLASSIFICATIONINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif