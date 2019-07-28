#include "use_fmt.h"
#include "fmt\time.h"
#include <time.h>

Use_fmt::Use_fmt(/* args */)
{
}

Use_fmt::~Use_fmt()
{
}

 std::string Use_fmt::getTodayDate()
 {
    auto t = std::time(nullptr);
    struct tm newtime;
    localtime_s(&newtime, &t);
    return fmt::format("{:%Y-%m-%d}", newtime);
 }