#include <iostream>
#include <vector>

#include "IPAddress.h"


int main (int, char **)
{
	std::vector<std::string> list = { "10.1.5.133", "120.17.6.18", "121.2.4.255" };
	//std::vector<std::string> list = { "10.1.5", "1120.17.6.18", "121.2.4.255.189" };



	for (const auto &str : list)
	{
		auto addr = IPAddress::fromString(str);
		std::cout << str << " => " << addr.toString() << std::endl;
	}
	
	return 0;
}
