#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main()
{
    ::testing::InitGoogleTest();
    ::testing::InitGoogleMock();

    //::testing::GTEST_FLAG(filter) = "SimpleMathTest.*";   //use this to filter tests to run

    RUN_ALL_TESTS();
    return 0;
}

