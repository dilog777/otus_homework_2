#include "IPFilter.h"

#include <algorithm>
#include <iterator>

#include "IPAddress.h"


std::vector<IPAddress> IPFilter::filter(const std::vector<IPAddress> &list, const FilterFunc &filter)
{
	std::vector<IPAddress> result;
	std::copy_if(list.begin(), list.end(), std::back_inserter(result), filter);
	return result;
}