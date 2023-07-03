#pragma once

#include <functional>
#include <vector>

struct IPAddress;


class IPFilter
{
public:
	using FilterFunc = std::function<bool(const IPAddress&)>;
	static std::vector<IPAddress> filter(const std::vector<IPAddress> &list, const FilterFunc &filter);
};

