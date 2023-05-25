#include <gtest/gtest.h>

#include "IPAddress.h"


TEST(test_ip_address, test_load_from_string)
{
	auto addressStr = "155.71.1.255";
	auto address = IPAddress::fromString(addressStr);
	EXPECT_TRUE(address.part0 == 155);
	EXPECT_TRUE(address.part1 == 71);
	EXPECT_TRUE(address.part2 == 1);
	EXPECT_TRUE(address.part3 == 255);
}



TEST(test_ip_address, test_save_to_string)
{
	auto srcAddressStr = "32.0.164.18";
	auto address = IPAddress::fromString(srcAddressStr);
	auto newAddressStr = address.toString();
	EXPECT_TRUE(srcAddressStr == newAddressStr);
}



int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
