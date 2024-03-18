#ifndef KARTSPLITSINFO_H
#define KARTSPLITSINFO_H

#include "../BaseInfo/BaseInfo.h"

class KartSplitsInfo : public BaseInfo<KartSplitsInfo_t>
{
public:
    KartSplitsInfo() : BaseInfo<KartSplitsInfo_t>(MB_KARTSPLITSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif