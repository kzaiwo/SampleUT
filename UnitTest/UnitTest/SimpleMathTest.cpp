#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <../../../ProdCode/ProdCode/ProdCode/SimpleMath.h>

class SimpleMathTest : public ::testing::Test
{
public:
    void SetUp()
    {
        sut_ = std::make_unique<SimpleMath>();
    }

    void TearDown()
    {}

protected:
    std::unique_ptr<SimpleMath> sut_;
};

TEST_F(SimpleMathTest, addWholeNumbers)
{
    EXPECT_EQ(23, sut_->add(20, 3));
}

TEST_F(SimpleMathTest, successfullyAddFloatingNumbers)
{
    EXPECT_FLOAT_EQ(25.8, sut_->add(24.5, 1.3));
}

TEST_F(SimpleMathTest, successfullyAddNegativeNumbers)
{
    EXPECT_EQ(-230, sut_->add(-200, -30));
}

TEST_F(SimpleMathTest, divideWholeNumbers)
{
    EXPECT_EQ(10, sut_->divide(50, 5));
}

TEST_F(SimpleMathTest, handleDivideException)
{
    EXPECT_THROW(sut_->divide(50, 0), std::logic_error);
}
