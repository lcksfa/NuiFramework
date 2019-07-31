#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fakeit.hpp"
#include "string_format.h"
#include "db.h"
#include "log.h"
#include "Calculator.h"

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

using namespace fakeit;
TEST_CASE("Calculate with two valid numbers --> server called") {
    Mock<DataAccess> fakeDataAccess;

    auto data = std::make_pair(1, 2);
    When(Method(fakeDataAccess, GetData)).Return(data);

    std::string dummy = "http://base";
    Mock<RestApiClient> fakeClient;

    When(Method(fakeClient, HttpGet)).Return("3");

    Calculator calculator(fakeDataAccess.get(), fakeClient.get());

    REQUIRE(calculator.CalculateNextData() == 3);

    Verify(Method(fakeClient, HttpGet)).AtLeastOnce();
}