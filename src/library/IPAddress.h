#pragma once

#include <array>
#include <string>

static const size_t IP_ADDRESS_SIZE = 4;

using IPAddressPart = unsigned char;


class IPAddress
{
public:
	static IPAddress fromString(const std::string &string);

	std::string toString() const;

	IPAddressPart addressPart(int partIdx) const;
	void setAddressPart(int partIdx, IPAddressPart value);

private:
	std::array<IPAddressPart, IP_ADDRESS_SIZE> _parts;
};