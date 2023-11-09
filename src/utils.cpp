#include <algorithm>

#include "utils.hpp"


namespace Utils 
{
    std::string ToLower(std::string str)
    {
        std::transform(std::begin(str), std::end(str), std::begin(str),
                        [](unsigned char c) { return std::tolower(c); });
        return str;
    }

    bool HasWhiteSpaces(const std::string& str)
    {
        return str.find(' ') != std::string::npos;
    }
    
}