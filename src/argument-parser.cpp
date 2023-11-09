#include <iostream>

#include "argument-parser.hpp"
#include "utils.hpp"
#include "args.hpp"


void ArgumentParser::RegisterFlag(const std::string& flag) 
{

    if(!flag.empty() && !Utils::HasWhiteSpaces(flag)) 
    {
        this->flags[flag] = false;
    }
}

void ArgumentParser::RegisterOption(const std::string& option) 
{
    if(!option.empty() && !Utils::HasWhiteSpaces(option))
    {
        this->options[option] = "";
    }
}

bool ArgumentParser::IsFlagRegistered(const std::string& flag) const
{
    if(!flag.empty())
    {
        return this->flags.count(flag) == 1;
    }
    return false;
}

bool ArgumentParser::IsOptionRegistered(const std::string& option) const
{
    if(!option.empty())
    {
        return this->options.count(option) == 1;
    }
    return false;
}

bool ArgumentParser::GetFlag(const std::string& flag) const 
{
    if(!flag.empty()) 
    {
        auto flag_it = this->flags.find(flag);
        if(flag_it != std::end(this->flags))
        {
            return flag_it->second;
        }
    }

    return false;
}

const std::string& ArgumentParser::GetOptionsAsString(const std::string& option) const 
{
    if(!option.empty())
    {
        auto option_it = this->options.find(option);
        if(option_it != std::end(this->options))
        {
            return option_it->second;
        }
    }

    static std::string EmptyOption = "";
    return EmptyOption;
}


/*
    Modificar esse dois para dar um erro
*/
float32_t ArgumentParser::GetOptionAsFloat32(const std::string& option) const
{
    const std::string& optionValue = GetOptionsAsString(option);

    if(!optionValue.empty())
    {
        return std::stof(optionValue);
    }

    return -1; 
}

float64_t ArgumentParser::GetOptionAsFloat64(const std::string& option) const
{
    const std::string& optionValue = GetOptionsAsString(option);

    if(!optionValue.empty())
    {
        return std::stod(optionValue);
    }

    return -1; 
}

int32_t ArgumentParser::GetOptionAsInt32(const std::string& option) const
{
    const std::string& optionValue = GetOptionsAsString(option);

    if(!optionValue.empty()) 
    {
        return std::stoi(optionValue);
    }

    return -1;
}

int64_t ArgumentParser::GetOptionAsInt64(const std::string& option) const
{
    const std::string& optionValue = GetOptionsAsString(option);

    if(!optionValue.empty()) 
    {
        return std::stoll(optionValue);
    }

    return -1;
}

void ArgumentParser::SetHelpMessage(const std::string& help_message)
{
    this->help_message = help_message;
}

const std::string& ArgumentParser::GetHelpMessage() const
{
    return this->help_message;
}

// Talvez Criar um parser options e um parser flags

void ArgumentParser::ParserOption(const std::string& argument) 
{
    const size_t equalSingPos = argument.find('=');
    if(equalSingPos == std::string::npos) return;

    std::string optionName = argument.substr(0, equalSingPos);
    std::string optionValue = argument.substr(equalSingPos+1);

    optionName = Utils::ToLower(optionName);

    if(optionName.compare(Args::Options::SceneFile)) 
    {
        optionValue = Utils::ToLower(optionValue);
    }

    auto option_it = this->options.find(optionName);
    if(option_it != std::end(this->options))
    {
        option_it->second = optionValue;
    }
}

void ArgumentParser::ParserFlag(const std::string& argument)
{
    std::string arg = Utils::ToLower(argument);
    auto flag_it = this->flags.find(arg);
    if(flag_it != std::end(this->flags))
    {
        flag_it->second = true;
    }
}

void ArgumentParser::Parser(int32_t argc, const char* argv[])
{
    if(argc <= 1 && argv == nullptr) return;
    
    for(int32_t i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if(arg.length() < 3) continue;


        if(arg[0] == '-' && arg[1] == '-')
        {
            arg = arg.substr(2);

            if(arg.find_first_of('=') != std::string::npos)
            {
                this->ParserOption(arg);
            } else {
               this->ParserFlag(arg);
            }    
        }
    }
}