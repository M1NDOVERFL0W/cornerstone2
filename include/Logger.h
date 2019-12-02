#ifndef CORNERSTONE2_LOGGER_H
#define CORNERSTONE2_LOGGER_H

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/logging.h>

void cornerstoneLogHandler(google::protobuf::LogLevel level, const char* filename, int line, const std::string& message);
void initializeLogger(const google::protobuf::LogLevel& level);

#endif //CORNERSTONE2_LOGGER_H
