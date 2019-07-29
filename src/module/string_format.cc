#include "string_format.h"
#include "fmt\time.h"
#include <time.h>

StringFormat::StringFormat(/* args */) {}

StringFormat::~StringFormat() {}

std::string StringFormat::getTodayDate() {
    auto t = std::time(nullptr);
    struct tm newtime;
    localtime_s(&newtime, &t);
    return fmt::format("{:%Y-%m-%d}", newtime);
}