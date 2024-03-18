#ifndef BASEINFO_H
#define BASEINFO_H

#include <iostream>
#include <string>
#include <napi.h>
#include "../../MappedBuffer/MappedBuffer.h"

template <typename T>
class BaseInfo
{
protected:
    MappedBuffer<T> *buffer;
    T *view;

    template <unsigned S>
    std::string GetStringFromChar(char (&value)[S]);

    template <typename T2, unsigned S>
    int GetArrayLength(T2 (&(value))[S]);

public:
    bool connected = false;
    BaseInfo(std::string name);
    void Connect();
    void Disconnect();
    virtual Napi::Value GetNapiObject(Napi::Env env);
};

#include "BaseInfo.cpp"

#endif