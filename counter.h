#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

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
