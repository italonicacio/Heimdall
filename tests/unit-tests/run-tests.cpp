#include <gtest/gtest.h>
#include <cstdint>

int32_t main(int32_t argc, char* argv[]) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}