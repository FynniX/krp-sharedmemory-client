#include "BaseInfo.h"

#ifndef BASEINFO_CPP
#define BASEINFO_CPP

template <typename T>
BaseInfo<T>::BaseInfo(std::string name) {
    buffer = new MappedBuffer<T>(name);
}

template <typename T>
void BaseInfo<T>::Connect() {
    if(connected) return;
    
    try {
        buffer->open();
    } catch (std::runtime_error) {
        connected = false;
        return;
    }

    view = buffer->view();
    connected = true;
}

template <typename T>
void BaseInfo<T>::Disconnect() {
    if(!connected) return;
    buffer->close();
    connected = false;
}

template <typename T>
Napi::Value BaseInfo<T>::GetNapiObject(Napi::Env env) {
    return env.Undefined();
}

template <typename T>
template <unsigned S>
std::string BaseInfo<T>::GetStringFromChar(char (&value)[S]) {
    //parsed char array as ansi
    std::string ansi_str = value;

    //Convert from ansi to wstring
    int count = MultiByteToWideChar(CP_ACP, 0, ansi_str.c_str(), ansi_str.length(), NULL, 0);
    std::wstring wide_str(count, 0);
    MultiByteToWideChar(CP_ACP, 0, ansi_str.c_str(), ansi_str.length(), &wide_str[0], count);

    //Convert from wstring to utf8
    int count2 = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), wide_str.length(), NULL, 0, NULL, NULL);
    std::string utf8_str(count2, 0);
    WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, &utf8_str[0], count2, NULL, NULL);
    return utf8_str;
}

template <typename T>
template <typename T2, unsigned S>
int BaseInfo<T>::GetArrayLength(T2 (&(value))[S]) {
    return S;
}

#endif