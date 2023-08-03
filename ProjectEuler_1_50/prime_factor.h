#pragma once

#include <vector>
#include "../../MonteCarlo/MonteCarlo/Primes.h"

using u64 = uint64_t;

void largest_prime_factor_3()
{
	const u64 number = 600'851'475'143;
	double square_root = sqrt(number);
	u64 square_root_ll = static_cast<u64>(square_root);

	Primes_List pl(square_root_ll);
	Primes primes(pl, square_root_ll);

	u64 largest_prime_divisor = 0;

	for (auto rev_it = primes.get_last_index(); rev_it >= 2; --rev_it)
	{
		if (number % primes.get_ith_prime(rev_it) == 0)
		{
			largest_prime_divisor = primes.get_ith_prime(rev_it);
			break;
		}
	}
	std::cout << "Largest Prime Factor = " << largest_prime_divisor << '\n';
}
