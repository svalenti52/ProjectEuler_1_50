#pragma once

#include <vector>
#include <iostream>
#include "../repos/MonteCarlo/MonteCarlo/Primes.h"

using u64 = uint64_t;

bool div_four_distinct_primes(u64 number, Primes& pp)
{
	int count = 0;
	//u64 ub = static_cast<u64>(std::sqrt(static_cast<double>(number))) + 1;

	for (u64 ix = 0; pp.get_ith_prime(ix) <= number/2+1; ++ix)
	{
		if (number % pp.get_ith_prime(ix) == 0)
			++count;
	}
	if (count == 4) return true;
	return false;
}


void prime_factors_4()
{
	using namespace std;
	Primes_List pl(1'000'000);
	Primes primes(pl, 1'000'000);

	int consecutive_count = 0;
	int last_number = 0;

	for (u64 ix = 100; ix <= 1'000'000; ++ix)
	{
		if (div_four_distinct_primes(ix, primes))
		{
			++consecutive_count;
			if (consecutive_count == 4)
			{
				last_number = ix;
				break;
			}
			//cout << ix << ", ";
		}
		else
			consecutive_count = 0;
	}

	cout << "\nLast Number = " << last_number-3 << '\n';
}
