#include "Traveller_NonMock.h"


Traveller_NonMock::Traveller_NonMock()
{
    travellers.clear();
}

Traveller_NonMock::~Traveller_NonMock()
{}

//Add traveller (name and continent) to a map
void Traveller_NonMock::addTraveller(const std::string& name, const std::string& country)
{
    continentHelper_ = std::make_unique<ContinentHelper>(); //can't inject mock since this is instantiated inside the method
    auto continent = continentHelper_->getContinent(country);   //external dependency
    travellers.insert(std::make_pair(name, continent));
}

//Checks map, if traveller's continent is Asia, add to vector to be returned
std::vector<std::string> Traveller_NonMock::getAsianTravellers()
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
std::vector<std::string> Traveller_NonMock::getAllTravellers()
{
    std::vector<std::string> travellerNames = {};

    for (auto it = travellers.begin(); it != travellers.end(); ++it)
    {
        travellerNames.push_back(it->first);
    }
    return travellerNames;
}
