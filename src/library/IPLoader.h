#pragma once

#include <string>
#include <vector>

struct IPAddress;


class IPLoader
{
public:
	std::vector<IPAddress> load(const std::string &filePath) const;

private:
	std::vector<std::string> readFromStdIn() const;
	std::vector<std::string> readFromFile(const std::string &filePath) const;

	std::vector<IPAddress> parse(const std::vector<std::string> &list) const;
};

