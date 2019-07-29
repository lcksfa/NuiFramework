#include "log.h"

Logme::Logme(/* args */) {
    // Set the default logger to file logger
    AllocConsole();
    logger_ = spdlog::stdout_color_mt("console1");
    // console->info("Welcome to spdlog!");
    // spdlog::info("Welcome to spdlog!");
    // spdlog::error("Some error message with arg: {}", 1);

    // spdlog::warn("Easy padding in numbers like {:08d}", 12);
    // spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    // spdlog::info("Support for floats {:03.2f}", 1.23456);
    // spdlog::info("Positional args are {1} {0}..", "too", "supported");
    // spdlog::info("{:<30}", "left aligned");

    // spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    // spdlog::debug("This message should be displayed..");

    // // change log pattern
    // spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // // Compile time log levels
    // // define SPDLOG_ACTIVE_LEVEL to desired level
    // SPDLOG_TRACE("Some trace message with param {}", {});
    // SPDLOG_DEBUG("Some debug message");

    //     auto file_logger = spdlog::basic_logger_mt("basic_logger", "basic.txt");
    // spdlog::set_default_logger(file_logger);

    // auto console = spdlog::stdout_color_mt("console");
    // spdlog::get("console")->info("loggers can be retrieved from a global registry using the
    // spdlog::get(logger_name)");
}

std::shared_ptr<spdlog::logger> Logme::get() { return logger_; }

Logme::~Logme() { spdlog::drop_all(); }