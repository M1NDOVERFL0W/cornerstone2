#include "Logger.h"

google::protobuf::LogLevel logLevel = ;

void cornerstoneLogHandler(google::protobuf::LogLevel level, const char* filename, int line, const std::string& message)
{
    if (level < GOOGLE_PROTOBUF_MIN_LOG_LEVEL) {
        return;
    }

    static const char* level_names[] = { "INFO", "WARNING", "ERROR", "FATAL" };
    fprintf(stderr, "[cornerstone2 %s %s:%d] %s\n",
    level_names[level], filename, line, message.c_str());
    fflush(stderr);
}