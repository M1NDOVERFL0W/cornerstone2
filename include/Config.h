#ifndef CORNERSTONE2_CONFIG_H
#define CORNERSTONE2_CONFIG_H

#include <string>

class Config final
{
private:
    std::string srcPath;
    std::string dstPath;
    std::string moduleName;
    std::string precompiledHeader;
    std::string wrappersPath;
    std::string companyName;

    static Config* instance;

public:
    Config(const std::string& _srcPath, const std::string& _dstPath,
            const std::string& _moduleName, const std::string& _precompiledHeader,
            const std::string& _wrappersPath, const std::string& _conpanyName);

    Config* get();

    void validate();
};



#endif //CORNERSTONE2_CONFIG_H
