//
// Created by Fynn Haupt on 05.06.2023.
//

#include <iostream>
#include <Windows.h>
#include "Utils.h"

template<unsigned S>
std::string GetStringFromChar(char (&value)[S]) {
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

template<typename T, unsigned S>
int GetArrayLength(T (&(value))[S]) {
    return S;
}