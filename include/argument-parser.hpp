#pragma once

#include <string>
#include <map>

#include "float-types.hpp"

template<typename T>
struct tag {using type = T;};

class ArgumentParser {
public:
    void RegisterFlag(const std::string& flag);

    void RegisterOption(const std::string& option);

    bool IsFlagRegistered(const std::string & flag) const;

    bool IsOptionRegistered(const std::string& option) const;

    bool GetFlag(const std::string& flag) const;

    template<typename T>
    T GetOptionAs(const std::string& option) const { return GetOptionAs(option, tag<T>{}); }

    const std::string& GetOptionAs(const std::string& option, tag<std::string>) const {return GetOptionsAsString(option); }

    float32_t GetOptionAs(const std::string& option, tag<float32_t>) const { return GetOptionAsFloat32(option); }
    float64_t GetOptionAs(const std::string& option, tag<float64_t>) const { return GetOptionAsFloat64(option); }


    int32_t GetOptionAs(const std::string& option, tag<int32_t>) const { return GetOptionAsInt32(option); }
    int64_t GetOptionAs(const std::string& option, tag<int64_t>) const { return GetOptionAsInt64(option); }


    void Parse(int32_t argc, const char* argv[]);

    void SetHelpMessage(const std::string& help_message);

    const std::string& GetHelpMessage() const;

private:
    std::map<std::string, bool> flags;
    std::map<std::string, std::string> options;
    std::string help_message;

    const std::string& GetOptionsAsString(const std::string& option) const;
    float32_t GetOptionAsFloat32(const std::string& option) const;
    float64_t GetOptionAsFloat64(const std::string& option) const;

    int32_t GetOptionAsInt32(const std::string& option) const;
    int64_t GetOptionAsInt64(const std::string& option) const;

    void ParserOption(const std::string& argument);
    void ParserFlag(const std::string& argument);



};

