#include <stdexcept>
#include <cstring>

#include "Config.h"

Config* Config::instance = nullptr;

Config::Config(const std::string& _srcPath, const std::string& _dstPath, const std::string& _moduleName,
               const std::string& _precompiledHeader, const std::string& _wrappersPath, const std::string& _conpanyName)
{
    srcPath = _srcPath;
    dstPath = _dstPath;
    moduleName = _moduleName;
    precompiledHeader = _precompiledHeader;
    wrappersPath = _wrappersPath;
    companyName = _conpanyName;

    instance = this;
}

Config* Config::get()
{
    if(!instance)
        throw std::runtime_error("Config has not been initialized!");

    return instance;
}

void Config::validate()
{
    if (srcPath.empty())
        throw std::runtime_error("srcPath must not be null or empty");

    if (dstPath.empty())
        throw std::runtime_error("dstPath must not be null or empty");

    for (const char& ch : moduleName)
    {
        if(!isdigit(ch) && !isalpha(ch))
            throw std::runtime_error("module_name, which is '" + moduleName + "' must contain only digits or letters");
    }

    if (wrappersPath.empty())
        throw std::runtime_error("wrappers_path must not be null or empty");

    if (companyName.empty())
        throw std::runtime_error("company_name must not be null or empty");

    for (const char& ch : companyName)
    {
        if (ch == '|')
            throw std::runtime_error("company_name, which is '" + companyName + "' mustn't contain '|'");
    }
}
