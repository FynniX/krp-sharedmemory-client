//
// Created by Fynn Haupt on 02.11.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_CAMERAINFOWORKER_H
#define KRP_SHAREDMEMORY_CLIENT_CAMERAINFOWORKER_H

class CameraInfoWorker : public Napi::AsyncWorker {
    CameraInfo &info;

public:
    CameraInfoWorker(Napi::Function &, CameraInfo &);

    virtual ~CameraInfoWorker() {};

    void Execute();

    void OnOK();
};


#endif //KRP_SHAREDMEMORY_CLIENT_CAMERAINFOWORKER_H
