//
// Created by Fynn Haupt on 05.06.2023.
//

#include <iostream>
#include "Utils.h"

template<unsigned S>
std::string GetStringFromChar(char (&value)[S]) {
    std::string str = value;
    return str;
}

template<typename T, unsigned S>
int GetArrayLength(T (&(value))[S]) {
    return S;
}