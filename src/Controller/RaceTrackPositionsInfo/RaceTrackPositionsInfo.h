#ifndef RACETRACKPOSITIONSINFO_H
#define RACETRACKPOSITIONSINFO_H

#include "../BaseInfo/BaseInfo.h"

class RaceTrackPositionsInfo : public BaseInfo<RaceTrackPositionsInfo_t>
{
public:
    RaceTrackPositionsInfo() : BaseInfo<RaceTrackPositionsInfo_t>(MB_RACETRACKPOSITIONSINFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif