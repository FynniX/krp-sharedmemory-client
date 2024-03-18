#ifndef KARTSESSIONINFO_H
#define KARTSESSIONINFO_H

#include "../BaseInfo/BaseInfo.h"

class KartSessionInfo : public BaseInfo<KartSessionInfo_t>
{
public:
    KartSessionInfo() : BaseInfo<KartSessionInfo_t>(MB_KARTSESSIONINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif