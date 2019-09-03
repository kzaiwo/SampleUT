#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "ContinentHelper.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT Traveller_NonMock
{
public:
    Traveller_NonMock();
    virtual ~Traveller_NonMock();

    void addTraveller(const std::string& name, const std::string& continent);
    std::vector<std::string> getAsianTravellers();
    std::vector<std::string> getAllTravellers();

private:
    std::map<std::string, std::string> travellers;
    std::unique_ptr<ContinentHelper> continentHelper_;
};

