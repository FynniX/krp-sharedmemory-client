#ifndef PLUGININFO_H
#define PLUGININFO_H

#include "../BaseInfo/BaseInfo.h"

class PluginInfo : public BaseInfo<PluginInfo_t>
{
public:
    PluginInfo() : BaseInfo<PluginInfo_t>(MB_PLUGININFO_FILE_NAME) {}
    Napi::Value GetNapiObject(Napi::Env env);
};

#endif