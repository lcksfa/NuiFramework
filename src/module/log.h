#pragma once
#include <string>
#include <memory>
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
    void info(const std::string& msg);
private:
    std::shared_ptr<spdlog::logger> logger_;
};
