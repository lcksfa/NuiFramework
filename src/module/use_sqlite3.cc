#include "use_sqlite3.h"
#include "sqlite3.h"
Use_sqlite3::Use_sqlite3(/* args */)
{
}

Use_sqlite3::~Use_sqlite3()
{
}

std::string Use_sqlite3:: printVersion(){
    return sqlite3_libversion();
}