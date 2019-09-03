
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <../../../ProdCode/ProdCode/ProdCode/Traveller.h>
#include "ContinentHelperMock.h"

using namespace ::testing;

class TravellerTest : public ::testing::Test
{
public:
    void SetUp()
    {
        continentHelperMock_ = std::make_unique<ContinentHelperMock>();
        sut_ = std::make_unique<Traveller>(continentHelperMock_.get());
    }

protected:
    std::unique_ptr<Traveller> sut_;
    std::unique_ptr<ContinentHelperMock> continentHelperMock_;
};

TEST_F(TravellerTest, shouldAddNewTravellers)
{
    EXPECT_CALL(*continentHelperMock_, getContinent("Philippines")).WillRepeatedly(Return("Asia"));
    sut_->addTraveller("Kay", "Philippines");

    EXPECT_CALL(*continentHelperMock_, getContinent("Singapore")).WillRepeatedly(Return("Asia"));
    sut_->addTraveller("Catherine", "Singapore");

    EXPECT_THAT(sut_->getAllTravellers(), testing::UnorderedElementsAre("Kay", "Catherine"));
}

TEST_F(TravellerTest, shouldGetAsianTravellers)
{
    EXPECT_CALL(*continentHelperMock_, getContinent("Philippines")).WillRepeatedly(Return("Asia"));
    EXPECT_CALL(*continentHelperMock_, getContinent("Poland")).WillRepeatedly(Return("Europe"));
    EXPECT_CALL(*continentHelperMock_, getContinent("Singapore")).WillRepeatedly(Return("Asia"));

    sut_->addTraveller("Kay", "Philippines");
    sut_->addTraveller("Cat", "Poland");
    sut_->addTraveller("Catherine", "Singapore");

    EXPECT_EQ(2, sut_->getAsianTravellers().size());
}

//Test is just added to show mock functionality
TEST_F(TravellerTest, shouldNotAddAsAsianTravellersIfContinentIsEurope)
{
    //This EXPECT_CALL proves that the mock does not use the actual class (ContinentHelper)
    //And just use the mocked implementation - we want everything to return as Europe and we shall get it!
    //Underscore _ is a wildcard, it will not check the value being passed in getContinent()
    EXPECT_CALL(*continentHelperMock_, getContinent(_)).WillRepeatedly(Return("Europe"));

    sut_->addTraveller("Kay", "Philippines");
    sut_->addTraveller("Catherine", "Singapore");

    EXPECT_EQ(0, sut_->getAsianTravellers().size());
    EXPECT_EQ(2, sut_->getAllTravellers().size());
}
