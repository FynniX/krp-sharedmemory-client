#ifndef TRACKSEGMENTSINFO_H
#define TRACKSEGMENTSINFO_H

#include "../BaseInfo/BaseInfo.h"

class TrackSegmentsInfo : public BaseInfo<TrackSegmentsInfo_t>
{
public:
    TrackSegmentsInfo() : BaseInfo<TrackSegmentsInfo_t>(MB_TRACKSEGMENTSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif