#pragma once

#include <iostream>

using u64 = uint64_t;

u64 last_10_digits(u64 x)
{
	// raise x to the x power
	// but only track the lower 10 digits

	u64 number_10_digits = 1;
	for (u64 ix = 0; ix < x; ++ix)
	{
		number_10_digits *= x;
		number_10_digits %= 10'000'000'000;
	}
	return number_10_digits;
}

void self_powers()
{
	using namespace std;

	u64 sum_10 = 0;
	for (u64 ix = 1; ix <= 1000; ++ix)
	{
		u64 self_power = last_10_digits(ix);
		sum_10 += self_power;
		sum_10 %= 10'000'000'000;
		cout << self_power << '\n';
	}
	cout << "10 least significant digits of sum of self powers = " << sum_10 << '\n';
}
