#include <stdexcept>
#include <utility>

#include "google/protobuf/stubs/logging.h"

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
    GOOGLE_CHECK_NOTNULL(instance);

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
    GOOGLE_CHECK_NOTNULL(instance);

    return instance->_srcPath;
}

const std::string& Config::dstPath()
{
    GOOGLE_CHECK_NOTNULL(instance);

    return instance->_dstPath;
}

const std::string& Config::moduleName()
{
    GOOGLE_CHECK_NOTNULL(instance);

    return instance->_moduleName;
}

const std::string& Config::precompiledHeader()
{
    GOOGLE_CHECK_NOTNULL(instance);

    return instance->_precompiledHeader;
}

const std::string &Config::wrappersPath()
{
    GOOGLE_CHECK_NOTNULL(instance);

    return instance->_wrappersPath;
}

const std::string& Config::companyName()
{
    GOOGLE_CHECK_NOTNULL(instance);

    return instance->_companyName;
}
