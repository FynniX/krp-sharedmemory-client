//
// Created by Fynn Haupt on 05.06.2023.
//

#ifndef KRP_SHAREDMEMORY_PLUGIN_MAPPEDBUFFER_H
#define KRP_SHAREDMEMORY_PLUGIN_MAPPEDBUFFER_H

template<typename MappedBufferT>
class MappedBuffer {
    HANDLE file = nullptr;
    MappedBufferT *buffer = nullptr;
    std::string BUFFER_NAME;
    int BUFFER_SIZE_BYTES;

public:
    explicit MappedBuffer(std::string);

    void create();

    void open();

    MappedBufferT *view();

    void write();

    void close();

    std::string getBufferName();
};


#endif //KRP_SHAREDMEMORY_PLUGIN_MAPPEDBUFFER_H
