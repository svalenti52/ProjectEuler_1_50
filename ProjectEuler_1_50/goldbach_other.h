#pragma once

#include <vector>
#include <iostream>
#include "../repos/MonteCarlo/MonteCarlo/Primes.h"

using u64 = uint64_t;

void goldback_other()
{
	using namespace std;
	Primes_List pl(1'000'000);
	Primes primes(pl, 1'000'000);

	vector<u64> double_squares;

	auto dbl_sqrs = [&double_squares](u64 i) {for (u64 ix = 1; ix < i; ++ix) double_squares.emplace_back(2 * ix * ix); };

	dbl_sqrs(10'000);

	u64 number = 0;

	for (u64 odd_composite = 5; odd_composite < 10'000; odd_composite += 2)
	{
		bool found = true;
		if (pl.is_prime(odd_composite)) continue;
		for (u64 px = 0; px < primes.get_last_index() + 1; ++px)
		{
			if (primes.get_ith_prime(px) > odd_composite) break;
			u64 pot_dbl_sqr = odd_composite - primes.get_ith_prime(px);
			auto dbl_sqr_it = find(double_squares.begin(), double_squares.end(), pot_dbl_sqr);
			if (dbl_sqr_it == double_squares.end())
			{
				found = false;
				continue;
			}
			found = true;
			break;
		}
		if (!found)
		{
			number = odd_composite;
			break;
		}
	}

	cout << number << '\n';

	//for (int d : double_squares)
	//	cout << d << ", ";
	//cout << '\n';
}
