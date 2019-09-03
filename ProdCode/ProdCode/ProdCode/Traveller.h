#pragma once

#include <string>
#include <vector>
#include <map>

#include "ContinentHelper.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT Traveller
{
public:
    Traveller(ContinentHelper* continentHelper);
    virtual ~Traveller();

    void addTraveller(const std::string& name, const std::string& continent);
    std::vector<std::string> getAsianTravellers();
    std::vector<std::string> getAllTravellers();

private:
    std::map<std::string, std::string> travellers;
    ContinentHelper* continentHelper_;
};

