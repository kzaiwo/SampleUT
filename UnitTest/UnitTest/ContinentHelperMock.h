#include <gmock/gmock.h>
#include "../../ProdCode/ProdCode/ProdCode/ContinentHelper.h"

class ContinentHelperMock : public ContinentHelper
{
public:
    MOCK_METHOD1(getContinent, std::string(const std::string& country));
};