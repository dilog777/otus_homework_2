#include "IPAddress.h"

#include "commonFunctions.h"


static const char IP_ADDRESS_DELIMITER = '.';


IPAddressPart string_to_address_part(const std::string &string)
{
	try
	{
		int value = std::stoi(string);
		return static_cast<IPAddressPart>(value);
	}
	catch (...)
	{
		return {};
	}
}



IPAddress IPAddress::fromString(const std::string &string)
{
	auto stringParts = split(string, IP_ADDRESS_DELIMITER);
	if (stringParts.size() != IP_ADDRESS_SIZE)
		return {};

	IPAddress address{};
	for (int i = 0; i < IP_ADDRESS_SIZE; ++i)
	{
		auto part = string_to_address_part(stringParts[i]);
		address.setAddressPart(i, part);
	}

	return address;
}



std::string IPAddress::toString() const
{
	std::string result;

	for (auto it = _parts.cbegin(); it != _parts.cend(); ++it)
	{
		if (it != _parts.cbegin())
			result += IP_ADDRESS_DELIMITER;

		result += std::to_string(*it);
	}

	return result;
}



IPAddressPart IPAddress::addressPart(int partIdx) const
{
	if (partIdx < 0 || partIdx >= IP_ADDRESS_SIZE)
		return {};

	return _parts[partIdx];
}



void IPAddress::setAddressPart(int partIdx, IPAddressPart value)
{
	if (partIdx < 0 || partIdx >= IP_ADDRESS_SIZE)
		return;

	_parts[partIdx] = value;
}
