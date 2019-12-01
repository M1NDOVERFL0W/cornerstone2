#ifndef CORNERSTONE2_CONFIG_H
#define CORNERSTONE2_CONFIG_H

#include <string>

class Config final
{
private:
    const std::string srcPath;
    const std::string dstPath;
    const std::string moduleName;
    const std::string precompiledHeader;
    const std::string wrappersPath;
    const std::string companyName;

    static Config* instance;

public:
    Config(std::string  _srcPath, std::string  _dstPath,
            std::string  _moduleName, std::string  _precompiledHeader,
            std::string  _wrappersPath, std::string  _companyName);

    Config* get();

    ~Config();

    void validate();
};



#endif //CORNERSTONE2_CONFIG_H
