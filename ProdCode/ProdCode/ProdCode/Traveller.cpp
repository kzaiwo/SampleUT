#include "Traveller.h"

Traveller::Traveller(ContinentHelper* continentHelper) :
    continentHelper_(continentHelper)
{
    travellers.clear();
}

Traveller::~Traveller()
{}

//Add traveller (name and continent) to a map
void Traveller::addTraveller(const std::string& name, const std::string& country)
{
    auto continent = continentHelper_->getContinent(country);   //external dependency
    travellers.insert(std::make_pair(name, continent));
}

//Checks map, if traveller's continent is Asia, add to vector to be returned
std::vector<std::string> Traveller::getAsianTravellers()
{
    std::vector<std::string> asianTravellers = {};

    for (auto it = travellers.begin(); it != travellers.end(); ++it)
    {
        if (it->second == "Asia")
        {
            asianTravellers.push_back(it->first);
        }
    }
    return asianTravellers;
}

//Gets all traveller names
std::vector<std::string> Traveller::getAllTravellers()
{
    std::vector<std::string> travellerNames = {};

    for (auto it = travellers.begin(); it != travellers.end(); ++it)
    {
        travellerNames.push_back(it->first);
    }
    return travellerNames;
}
