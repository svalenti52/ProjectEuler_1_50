#pragma once

// prime_sum_lt_million.h

#include "..\..\MonteCarlo\MonteCarlo\Primes.h"

using u64 = uint64_t;

void prime_sum_lt_million()
{
	const u64 ub = 1'000'000;
	Primes_List pl(ub);
	Primes primes(pl, ub);

	std::vector<u64> prime_seq;

	int max_sequence = 0;
	u64 max_prime_number = 2;
	u64 starting_ix = 0;

	for (u64 first_ix = 0; first_ix < 500'000; ++first_ix)
	{
		u64 p = 0;
		for (u64 ix = first_ix; ix < primes.get_last_index(); ++ix)
		{
			prime_seq.emplace_back(primes.get_ith_prime(ix));
			p += primes.get_ith_prime(ix);
			if (p < ub)
			{
				if (pl.is_prime(p))
				{
					// std::cout << p << "-" << prime_seq.size() << "-" << first_ix << ", ";
					if (prime_seq.size() > max_sequence)
					{
						max_sequence = prime_seq.size();
						max_prime_number = p;
						starting_ix = ix;
					}
				}
			}
			else
			{
				prime_seq.clear();
				break;
			}
		}
		// std::cout << '\n';
	}
	std::cout << "Max Sequence Number = " << max_sequence << "  Max Sum Prime Number = " << max_prime_number << '\n';
	std::cout << "Starting Index = " << starting_ix << '\n';
}
