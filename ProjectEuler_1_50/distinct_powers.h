#pragma once

#include <set>
#include <boost\multiprecision\cpp_int.hpp>

void distinct_powers()
{
	using namespace std;
	using namespace boost::multiprecision;

	set<cpp_int> unique_powers;

	for (int base = 2; base <= 100; ++base)
		for (int exponent = 2; exponent <= 100; ++exponent)
		{
			cpp_int x = 1;
			for (int expo = 1; expo <= exponent; ++expo)
				x *= base;
			unique_powers.insert(x);
		}

	cout << "Number of Distict Power Values = " << unique_powers.size() << '\n';
}
