//
// Created by Fynn Haupt on 17.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_PLUGININFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_PLUGININFOWORKER_H

class PluginInfoWorker : public Napi::AsyncWorker {
    PluginInfo &info;

public:
    PluginInfoWorker(Napi::Function &, PluginInfo &);

    virtual ~PluginInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_PLUGININFOWORKER_H
