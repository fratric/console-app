// app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

struct Line : public std::string {};

template<typename T> size_t counter(std::istream &vstup)
{
	return std::distance(std::istream_iterator<T>(vstup), std::istream_iterator<T>());
}

std::istream &operator >> (std::istream &stream, Line &line) 
{
	std::getline(stream, line);
	return stream;
}

int main(int argc, char *argv[])
{
	if (argc < 2 || argc>3) return -1;
	std::fstream fs;
	if (argc==3) {
		fs.open(argv[2], std::fstream::in);
		if (fs.bad())
		{
			return -1;
		}
	}
	std::istream &vstup = (argc == 3) ? fs : std::cin;

	if (argv[1]==std::string("-c")) {
		std::cout << counter<char>(vstup);
	}
	else if (argv[1] == std::string("-w")) {
		std::cout << counter<std::string>(vstup);
	}
	else if (argv[1] == std::string("-e")) {
		std::cout << counter<Line>(vstup);
	}
	else {
		return -1;
	}

	return 0;
}
