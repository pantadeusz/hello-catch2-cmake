#include <catch2/catch.hpp>

#include <fibonacci.hpp>

TEST_CASE("simple test case calculating fibonacci for 10th element","[fibonacci]") {
    REQUIRE(fibonacci(10) == 55);
}
