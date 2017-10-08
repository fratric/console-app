// unittest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "counter.h"

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1)*number;
}

TEST_CASE("testovanie", "[counter]") {
	std::fstream fs;
	fs.open("ReadMe.txt", std::fstream::in);
	if (!fs.bad())
	{
		std::istream &vstup = fs;
		REQUIRE(counter<Line>(vstup) == 37);
		REQUIRE(counter<Line>(vstup) == 53);
	}

//	REQUIRE(Factorial(4) == 6);
}