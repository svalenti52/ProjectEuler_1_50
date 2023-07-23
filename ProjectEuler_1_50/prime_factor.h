#pragma once

#include <vector>
#include "../../MonteCarlo/MonteCarlo/Primes.h"

using u64 = uint64_t;

u64 largest_prime_factor(u64 number)
{
	double square_root = sqrt(number);
	u64 square_root_ll = static_cast<u64>(square_root);

	Primes_List pl(square_root_ll);
	Primes primes(pl, square_root_ll);

	for (auto rev_it = primes.get_last_index(); rev_it >= 2; --rev_it)
	{
		if (number % primes.get_ith_prime(rev_it) == 0)
		{
			return primes.get_ith_prime(rev_it);
		}
	}
	return 0;
}
