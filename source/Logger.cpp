#include "Logger.h"

google::protobuf::LogLevel logLevel = google::protobuf::LogLevel::LOGLEVEL_INFO;

void cornerstoneLogHandler(google::protobuf::LogLevel level, const char* filename, int line, const std::string& message)
{
    if (level < logLevel)
        return;

    static const char* level_names[] = { "INFO", "WARNING", "ERROR", "FATAL" };
    fprintf(stderr, "[cornerstone2 %s %s:%d] %s\n",
            level_names[level], filename, line, message.c_str());
    fflush(stderr);
}

void initializeLogger(const google::protobuf::LogLevel& level)
{
    logLevel = level;
    google::protobuf::SetLogHandler(&cornerstoneLogHandler);

}