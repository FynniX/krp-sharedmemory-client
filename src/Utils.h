//
// Created by Fynn Haupt on 07.06.2023.
//

#ifndef KRP_SHAREDMEMORY_CLIENT_UTILS_H
#define KRP_SHAREDMEMORY_CLIENT_UTILS_H

template<unsigned S>
std::string GetStringFromChar(char (&value)[S]);

template<typename T, unsigned S>
int GetArrayLength(T (&(value))[S]);

#endif //KRP_SHAREDMEMORY_CLIENT_UTILS_H
