#ifndef KARTTELEMETRYINFO_H
#define KARTTELEMETRYINFO_H

#include "../BaseInfo/BaseInfo.h"

class KartTelemetryInfo : public BaseInfo<KartTelemetryInfo_t>
{
public:
    KartTelemetryInfo() : BaseInfo<KartTelemetryInfo_t>(MB_KARTTELEMETRYINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif