#include <stdexcept>
#include <cstring>
#include <utility>

#include "Config.h"

Config* Config::instance = nullptr;

Config::Config(std::string  _srcPath, std::string  _dstPath, std::string  _moduleName,
               std::string  _precompiledHeader, std::string  _wrappersPath, std::string  _companyName) :
        srcPath(std::move(_srcPath)),
        dstPath(std::move(_dstPath)),
        moduleName(std::move(_moduleName)),
        precompiledHeader(std::move(_precompiledHeader)),
        wrappersPath(std::move(_wrappersPath)),
        companyName(std::move(_companyName))

{
    instance = this;
}

Config::~Config()
{
    if(instance)
        free(instance);
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
