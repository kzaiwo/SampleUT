#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <../../../ProdCode/ProdCode/ProdCode/Traveller_NonMock.h>

using namespace ::testing;

class TravellerNonMockTest : public ::testing::Test
{
public:
    void SetUp()
    {
        sut_ = std::make_unique<Traveller_NonMock>();
    }

protected:
    std::unique_ptr<Traveller_NonMock> sut_;
};

TEST_F(TravellerNonMockTest, shouldAddNewTravellers)
{
    sut_->addTraveller("Kay", "Philippines");
    sut_->addTraveller("Catherine", "Singapore");

    EXPECT_THAT(sut_->getAllTravellers(), testing::UnorderedElementsAre("Kay", "Catherine"));
}

TEST_F(TravellerNonMockTest, shouldGetAsianTravellers)
{
    sut_->addTraveller("Kay", "Philippines");
    sut_->addTraveller("Cat", "Poland");
    sut_->addTraveller("Catherine", "Singapore");

    EXPECT_EQ(2, sut_->getAsianTravellers().size());
}
