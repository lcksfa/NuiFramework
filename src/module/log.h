#pragma once
#include <string>
#include <memory>
#define SPDLOG_WCHAR_TO_UTF8_SUPPORT
#include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Logme
{
private:
    /* data */
public:
    Logme(/* args */);
    ~Logme();
    std::shared_ptr<spdlog::logger> get();
private:
    std::shared_ptr<spdlog::logger> logger_;
};
