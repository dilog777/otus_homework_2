#include "IPAddress.h"

#include <sstream>


static const char IP_ADDRESS_DELIMITER = '.';


IPAddress IPAddress::fromString(const std::string &string)
{
	std::stringstream stream(string);
	int p0, p1, p2, p3;
	char ch;
	stream >> p0 >> ch >> p1 >> ch >> p2 >> ch >> p3;
	
	return IPAddress{ p0, p1, p2, p3 };
}



std::string IPAddress::toString() const
{
	std::stringstream stream;
	stream << part0 << IP_ADDRESS_DELIMITER;
	stream << part1 << IP_ADDRESS_DELIMITER;
	stream << part2 << IP_ADDRESS_DELIMITER;
	stream << part3;
	
	return stream.str();
}



bool IPAddress::operator<(const IPAddress &r) const
{
	if (part0 != r.part0)
		return part0 < r.part0;

	if (part1 != r.part1)
		return part1 < r.part1;

	if (part2 != r.part2)
		return part2 < r.part2;
	
	return part3 < r.part3;
}



bool IPAddress::operator>(const IPAddress &r) const
{
	if (part0 != r.part0)
		return part0 > r.part0;

	if (part1 != r.part1)
		return part1 > r.part1;

	if (part2 != r.part2)
		return part2 > r.part2;
	
	return part3 > r.part3;
}