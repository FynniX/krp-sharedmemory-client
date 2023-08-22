//
// Created by Fynn Haupt on 16.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_PLUGININFO_H
#define KRP_SHAREDMEMORY_CLIENT_PLUGININFO_H

class PluginInfo {
    int lastId = -1;
    MappedBuffer <PluginInfo_t> controller = MappedBuffer<PluginInfo_t>("Local\\KRPSMP_PluginInfo");
public:
    int waitDelay = 1000;
    bool isConnected = false;

    void connect();

    PluginInfo_t *getView();

    void disconnect();

    std::string waitForChange();
};


#endif //KRP_SHAREDMEMORY_CLIENT_PLUGININFO_H
