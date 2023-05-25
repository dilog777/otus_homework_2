#include <algorithm>
#include <iostream>

#include "IPAddress.h"
#include "IPFilter.h"
#include "IPLoader.h"



void printAddressList(const std::vector<IPAddress> &list)
{
	for (const auto &address : list)
		std::cout << address.toString() << std::endl;
}



void printFilteredList(const std::vector<IPAddress> &list, const IPFilter::FilterFunc &filter)
{
	auto filtered_list = IPFilter::filter(list, filter);
	printAddressList(filtered_list);
}



int main (int argc, char *argv[])
{
	std::string filePath;
	if (argc > 1)
		filePath = argv[1];

	IPLoader loader;
	auto ip_list = loader.load(filePath);

	std::sort(ip_list.begin(), ip_list.end());

	auto filter1 = [](const IPAddress &address) -> bool
	{
		return address.part0 == 1;
	};

	auto filter2 = [](const IPAddress &address) -> bool
	{
		return address.part0 == 46 
			&& address.part1 == 70;
	};

	auto filter3 = [](const IPAddress &address) -> bool
	{
		return address.part0 == 46 
			|| address.part1 == 46
			|| address.part2 == 46
			|| address.part3 == 46;
	};

	printAddressList(ip_list);
	printFilteredList(ip_list, filter1);
	printFilteredList(ip_list, filter2);
	printFilteredList(ip_list, filter3);

	return 0;
}
