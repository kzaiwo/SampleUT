#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT ContinentHelper
{
public:
    ContinentHelper();
    virtual ~ContinentHelper();

    virtual std::string getContinent(const std::string& country);
};
