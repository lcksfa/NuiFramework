#include "db.h"
#include "sqlite3.h"
DB::DB(/* args */) {}

DB::~DB() {}

std::string DB::printVersion() { return sqlite3_libversion(); }