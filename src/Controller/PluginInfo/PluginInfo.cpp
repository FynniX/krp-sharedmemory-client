#include "PluginInfo.h"

Napi::Value PluginInfo::GetNapiObject(Napi::Env env) {
    if(!connected) return env.Undefined();

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("m_id", view->m_id);
    obj.Set("m_GameState", (int) view->m_GameState);
    obj.Set("m_TrackState", (int) view->m_TrackState);
    obj.Set("m_PluginRate", (int) view->m_PluginRate);
    obj.Set("m_PluginVersion", view->m_PluginVersion);
    obj.Freeze();

    return obj;
}