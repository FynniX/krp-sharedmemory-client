#ifndef RACECOMMUNICATIONSINFO_H
#define RACECOMMUNICATIONSINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceCommunicationsInfo : public BaseInfo<RaceCommunicationsInfo_t>
{
public:
    RaceCommunicationsInfo() : BaseInfo<RaceCommunicationsInfo_t>(MB_RACECOMMUNICATIONSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif