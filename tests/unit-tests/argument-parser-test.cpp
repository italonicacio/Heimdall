#include <gtest/gtest.h>

#include "argument-parser.hpp"

class ArgumentParserTest : public ::testing::Test
{
public:
	ArgumentParser* arg_parser = nullptr;

private:
	void SetUp() override {
		arg_parser = new ArgumentParser();
	}

	void TearDown() override {
		delete arg_parser;
	}
};

TEST_F(ArgumentParserTest, RegisterFlag) {
	std::string flag("my-flag");

	EXPECT_FALSE(arg_parser->IsFlagRegistered(flag));

	arg_parser->RegisterFlag(flag);

	EXPECT_TRUE(arg_parser->IsFlagRegistered(flag));
}

TEST_F(ArgumentParserTest, RegisterFlag_WhiteSpaces) {
	std::string flag("my flag");

	EXPECT_FALSE(arg_parser->IsFlagRegistered(flag));

	arg_parser->RegisterFlag(flag);

	EXPECT_FALSE(arg_parser->IsFlagRegistered(flag));
}

TEST_F(ArgumentParserTest, RegisterOption) {
	std::string option("my-option");

	EXPECT_FALSE(arg_parser->IsOptionRegistered(option));

	arg_parser->RegisterOption(option);

	EXPECT_TRUE(arg_parser->IsOptionRegistered(option));
}

TEST_F(ArgumentParserTest, RegisterOption_WhiteSpaces) {
	std::string option("my option");

	EXPECT_FALSE(arg_parser->IsOptionRegistered(option));

	arg_parser->RegisterOption(option);

	EXPECT_FALSE(arg_parser->IsOptionRegistered(option));
}

TEST_F(ArgumentParserTest, Parse) {
	std::array<const char*, 6> args =
	{
		"TestArgumentParser_Parse",
		"--flag",
		"--string=AaBbCcDd",
		"--string-str=AbCd",
		"--int=42",
		"--float=4.2"
	};

	arg_parser->RegisterFlag("flag");
	arg_parser->RegisterOption("string");
	arg_parser->RegisterOption("string-str");

	arg_parser->Parse(static_cast<int32_t>(args.size()), args.data());

	EXPECT_FALSE(arg_parser->GetFlag("unregistered_flag"));
	EXPECT_TRUE(arg_parser->GetFlag("flag"));

	EXPECT_EQ(arg_parser->GetOptionAs<std::string>("string"), "aabbccdd");
	EXPECT_EQ(arg_parser->GetOptionAs<std::string>("string-str"), "abcd");
}

TEST_F(ArgumentParserTest, Parse_IntegerOption) {
	std::array<const char*, 2> args =
	{
		"TestArgumentParser_Parse",
		"--int=42",
	};

	arg_parser->RegisterOption("int");

	arg_parser->Parse(static_cast<int32_t>(args.size()), args.data());

	EXPECT_EQ(arg_parser->GetOptionAs<int32_t>("int"), 42);
	EXPECT_EQ(arg_parser->GetOptionAs<int64_t>("int"), static_cast<int64_t>(42));
}

TEST_F(ArgumentParserTest, Parse_FloatOption) {
	std::array<const char*, 2> args =
	{
		"TestArgumentParser_Parse",
		"--float=4.2"
	};

	arg_parser->RegisterOption("float");

	arg_parser->Parse(static_cast<int32_t>(args.size()), args.data());

	EXPECT_FLOAT_EQ(arg_parser->GetOptionAs<float32_t>("float"), 4.2f);
	EXPECT_FLOAT_EQ(arg_parser->GetOptionAs<float64_t>("float"), 4.2);
}

TEST_F(ArgumentParserTest, Parse_InvalidFloatOption) {
	std::array<const char*, 2> args =
	{
		"TestArgumentParser_Parse",
		"--float=invalid"
	};

	arg_parser->RegisterOption("float");

	arg_parser->Parse(static_cast<int32_t>(args.size()), args.data());

	EXPECT_ANY_THROW(arg_parser->GetOptionAs<float32_t>("float"));
	EXPECT_ANY_THROW(arg_parser->GetOptionAs<float64_t>("float"));
}

TEST_F(ArgumentParserTest, Parse_InvalidIntegerOption) {
	std::array<const char*, 2> args =
	{
		"TestArgumentParser_Parse",
		"--int=invalid",
	};

	arg_parser->RegisterOption("int");

	arg_parser->Parse(static_cast<int32_t>(args.size()), args.data());

	EXPECT_ANY_THROW(arg_parser->GetOptionAs<int32_t>("int"));
	EXPECT_ANY_THROW(arg_parser->GetOptionAs<int64_t>("int"));
}

TEST_F(ArgumentParserTest, HelpMessage) {


	arg_parser->SetHelpMessage("this is a test");

	EXPECT_STREQ(arg_parser->GetHelpMessage().c_str(), "this is a test");
}
