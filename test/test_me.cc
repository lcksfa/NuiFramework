#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "string_format.h"
#include "db.h"
// #include "fmt\time.h"
// #include <string>
// #include <vector>
// #include "fmt\printf.h"
// #include <cstdio>
// #include <stdio.h>
#include "log.h"

TEST_CASE("normal test for test") { REQUIRE(1 == 1); }

TEST_CASE("testfmtlibrary", "date") {
    StringFormat f;
    REQUIRE(f.getTodayDate() == "2019-07-29");
}

TEST_CASE("testuseof_sqlite3", "printVersion") {
    DB sq3;
    REQUIRE(sq3.printVersion() == "3.29.0");
}

TEST_CASE("test sqdlog library", "the basic log") {
    Logme g;
    // g.info("ceui {} {}");
}
// TEST_CASE("TESTFMT2", "T_Normal") {
//     auto str = fmt::format("The is {}", 42);
//     REQUIRE(str == "The is 42");

//     std::vector<wchar_t> result;
//     fmt::format_to(back_inserter(result), L"{}", 42);
//     std::vector<wchar_t> march = {L'4', L'2'};
//     REQUIRE(march == result);

//     // NO ALLOCATIONS
//     fmt::basic_memory_buffer<char, 100> buffer;
//     fmt::format_to(buffer, "{}", 52);
//     auto result2 = fmt::to_string(buffer);
//     REQUIRE(result2 =="52");
// }

// TEST_CASE("TESEFMT3", "USE_DEFINED_LITERALS") {
//     // USER-DEFINED LITERALS
//     using namespace fmt::literals;
//     std::wstring message = L"The answer is {}"_format(42);
//     REQUIRE(message ==  L"The answer is 42");

//     auto udlstr = fmt::format("The answer is {the_answer}", "the_answer"_a = 42);
//     // equl to format(L"The answer is {the_answer}", arg("the_answer", 42));
//     REQUIRE(udlstr == "The answer is 42");

//     auto uslstr2 = fmt::format("My name is {my_name},i am {old} years old", "my_name"_a =
//     "lcksfa",
//                                "old"_a = 29);
//     REQUIRE(uslstr2 =="My name is lcksfa,i am 29 years old");

//     std::string message2 = "{0}{1}{0}"_format("abra", "cad");
//     REQUIRE(message2 == "abracadabra");
// }

// TEST_CASE("TESTFMT4", "T_File_") {
//     FILE *fp = nullptr;
//     fopen_s(&fp, "test.txt", "w+");
//     if (!fp) {
//         fmt::fprintf(stderr, "text.txt open failed!");
//     }
//     fmt::fprintf(fp, "Hello %s", "World.");

// }
