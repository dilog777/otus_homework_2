#include "IPAddress.h"

#include <sstream>


static const char IP_ADDRESS_DELIMITER = '.';


IPAddress IPAddress::fromString(const std::string &string)
{
	std::stringstream ss(string);
	int p0, p1, p2, p3;
	char ch;
	ss >> p0 >> ch >> p1 >> ch >> p2 >> ch >> p3;
	
	return IPAddress{ p0, p1, p2, p3 };
}



std::string IPAddress::toString() const
{
	std::stringstream ss;
	ss << part0 << IP_ADDRESS_DELIMITER;
	ss << part1 << IP_ADDRESS_DELIMITER;
	ss << part2 << IP_ADDRESS_DELIMITER;
	ss << part3;
	
	std::string result;
	ss >> result;
	return result;
}
