
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("some failing test")
{
  REQUIRE(1==1+1);
  
}
TEST_CASE("slow 1")
{
  system("sleep 3");
  
  REQUIRE(1==1);
}
TEST_CASE("slow 2")
{
  system("sleep 3");
  
  REQUIRE(1==1);
}
TEST_CASE("slow 3")
{
  system("sleep 3");
  
  REQUIRE(1==1);
}
TEST_CASE("slow 4")
{
  system("sleep 3");
  
  REQUIRE(1==1);
}
