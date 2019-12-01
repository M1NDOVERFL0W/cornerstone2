#ifndef CORNERSTONE2_CONFIG_H
#define CORNERSTONE2_CONFIG_H

#include <string>

class Config final
{
private:
    const std::string _srcPath;
    const std::string _dstPath;
    const std::string _moduleName;
    const std::string _precompiledHeader;
    const std::string _wrappersPath;
    const std::string _companyName;

    static Config* instance;

public:
    Config(std::string  _srcPath, std::string  _dstPath,
            std::string  _moduleName, std::string  _precompiledHeader,
            std::string  _wrappersPath, std::string  _companyName);

    ~Config();

    void validate();

    static const std::string& srcPath();

    static const std::string& dstPath();

    static const std::string& moduleName();

    static const std::string& precompiledHeader();

    static const std::string& wrappersPath();

    static const std::string& companyName();
};



#endif //CORNERSTONE2_CONFIG_H
