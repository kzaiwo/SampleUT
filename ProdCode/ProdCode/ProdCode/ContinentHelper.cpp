#pragma once
#include "ContinentHelper.h"

ContinentHelper::ContinentHelper()
{
}

ContinentHelper::~ContinentHelper()
{
}

std::string ContinentHelper::getContinent(const std::string& country)
{
    std::string continent = "Africa";

    const std::vector<std::string> ASIAN_COUNTRIES{ "Philippines", "Singapore", "Japan", "Korea", "China", "India", "Taiwan" };
    const std::vector<std::string> EUROPEAN_COUNTRIES{ "Germany", "Poland", "Ireland", "Switzerland" };

    if (std::any_of(ASIAN_COUNTRIES.cbegin(), ASIAN_COUNTRIES.cend(),
        [country](std::string asianCountry) { return asianCountry == country; }))
    {
        std::cout << country << " is an Asian country!" << std::endl;
        continent = "Asia";
    }
    else if (std::any_of(EUROPEAN_COUNTRIES.cbegin(), EUROPEAN_COUNTRIES.cend(),
        [country](std::string europeanCountry) { return europeanCountry == country; }))
    {
        std::cout << country << " is a European country!" << std::endl;
        continent = "Europe";
    }

    return continent;
}
