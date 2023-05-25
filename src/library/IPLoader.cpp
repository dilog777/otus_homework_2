#include "IPLoader.h"

#include <iostream>
#include <fstream>

#include "IPAddress.h"



std::vector<std::string> split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}



std::vector<IPAddress> IPLoader::load(const std::string &filePath) const
{
	std::vector<std::string> rawData;
	if (!filePath.empty())
		rawData = readFromFile(filePath);
	else
		rawData = readFromStdIn();

	return parse(rawData);
}



std::vector<std::string> IPLoader::readFromStdIn() const
{
	std::vector<std::string> result;

	for (std::string line; std::getline(std::cin, line);)
		result.push_back(line);

	return result;
}


std::vector<std::string> IPLoader::readFromFile(const std::string &filePath) const
{
	std::vector<std::string> result;

	std::ifstream stream(filePath);
	if (stream.is_open())
	{
		std::string line;
		while (std::getline(stream, line))
			result.push_back(line);
	}
	stream.close();

	return result;
}



std::vector<IPAddress> IPLoader::parse(const std::vector<std::string> &list) const
{
	std::vector<IPAddress> result;

	for (const auto &line : list)
	{
		auto lineParts = split(line, '\t');
		result.push_back(IPAddress::fromString(lineParts.at(0)));
	}

	return result;
}
