#include <stdexcept>
#include <utility>

#include "Config.h"

Config* Config::instance = nullptr;

Config::Config(std::string  __srcPath, std::string  __dstPath, std::string  __moduleName,
               std::string  __precompiledHeader, std::string  __wrappersPath, std::string  _companyName) :
        _srcPath(std::move(__srcPath)),
        _dstPath(std::move(__dstPath)),
        _moduleName(std::move(__moduleName)),
        _precompiledHeader(std::move(__precompiledHeader)),
        _wrappersPath(std::move(__wrappersPath)),
        _companyName(std::move(_companyName))

{
    instance = this;
}

Config::~Config()
{
    if(instance)
        free(instance);
}

void Config::validate()
{
    if (_srcPath.empty())
        throw std::runtime_error("srcPath must not be null or empty");

    if (_dstPath.empty())
        throw std::runtime_error("dstPath must not be null or empty");

    for (const char& ch : _moduleName)
    {
        if(!isdigit(ch) && !isalpha(ch))
            throw std::runtime_error("module_name, which is '" + _moduleName + "' must contain only digits or letters");
    }

    if (_wrappersPath.empty())
        throw std::runtime_error("wrappers_path must not be null or empty");

    if (_companyName.empty())
        throw std::runtime_error("company_name must not be null or empty");

    for (const char& ch : _companyName)
    {
        if (ch == '|')
            throw std::runtime_error("company_name, which is '" + _companyName + "' mustn't contain '|'");
    }
}

const std::string& Config::srcPath()
{
    return instance->_srcPath;
}

const std::string& Config::dstPath()
{
    return instance->_dstPath;
}

const std::string& Config::moduleName()
{
    return instance->_moduleName;
}

const std::string& Config::precompiledHeader()
{
    return instance->_precompiledHeader;
}

const std::string &Config::wrappersPath()
{
    return instance->_wrappersPath;
}

const std::string& Config::companyName()
{
    return instance->_companyName;
}
