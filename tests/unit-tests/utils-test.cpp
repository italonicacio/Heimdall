#include <gtest/gtest.h>


#include "utils.hpp"


TEST(UtilsTest, ToLower) 
{
    std::string upper_string("UPper StrINg");
    std::string lower_string = Utils::ToLower(upper_string);
    EXPECT_STREQ(lower_string.data(), "upper string");
}


TEST(UtilsTest, HasWhiteSpaces)
{
    std::string has_white_spaces("has white space");
    std::string has_no_white_spaces("has_no_white_spaces");
    std::string HasNoWhiteSpaces("HasNoWhiteSpaces");

    EXPECT_TRUE(Utils::HasWhiteSpaces(has_white_spaces));
    EXPECT_FALSE(Utils::HasWhiteSpaces(has_no_white_spaces));
    EXPECT_FALSE(Utils::HasWhiteSpaces(HasNoWhiteSpaces));

}