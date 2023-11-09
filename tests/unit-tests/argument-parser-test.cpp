#include <gtest/gtest.h>

#include "argument-parser.hpp"

class ArgumentParserTest : public ::testing::Test 
{
public:
    ArgumentParser* arg_parser = nullptr;
private:
    void SetUp() override 
    {
        arg_parser = new ArgumentParser();
    }

    void TearDown() override
    {
        delete arg_parser;
    }
};

TEST_F(ArgumentParserTest, RegisterFlag)
{
    std::string flag("my-flag");

    EXPECT_FALSE(arg_parser->IsFlagRegistered(flag));

    arg_parser->RegisterFlag(flag);

    EXPECT_TRUE(arg_parser->IsFlagRegistered(flag));
}

TEST_F(ArgumentParserTest, RegisterFlag_WhiteSpaces)
{
    std::string flag("my flag");

    EXPECT_FALSE(arg_parser->IsFlagRegistered(flag));

    arg_parser->RegisterFlag(flag);

    EXPECT_FALSE(arg_parser->IsFlagRegistered(flag));
}

TEST_F(ArgumentParserTest, RegisterOption)
{
    std::string option("my-option");

    EXPECT_FALSE(arg_parser->IsOptionRegistered(option));

    arg_parser->RegisterOption(option);

    EXPECT_TRUE(arg_parser->IsOptionRegistered(option));
}


TEST_F(ArgumentParserTest, RegisterOption_WhiteSpaces)
{
    std::string option("my option");

    EXPECT_FALSE(arg_parser->IsOptionRegistered(option));

    arg_parser->RegisterOption(option);

    EXPECT_FALSE(arg_parser->IsOptionRegistered(option));
}