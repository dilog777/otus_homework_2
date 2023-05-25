#pragma once

#include <string>


struct IPAddress
{
	int part0{ 0 };
	int part1{ 0 };
	int part2{ 0 };
	int part3{ 0 };

	std::string toString() const;
	static IPAddress fromString(const std::string &string);
};

