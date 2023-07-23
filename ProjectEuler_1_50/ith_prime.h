#pragma once
#include <cstdint>
#include "..\..\MonteCarlo\MonteCarlo\Primes.h"

using u64 = uint64_t;

u64 get_ith_prime(u64 seq)
{
	// since using 1 to get 2, 2 to get 3, 3 to 5
	--seq;
	if (seq > 1'000'000'000) return 0;
	const u64 upper_bound = 10'000'000;
	Primes_List pl(upper_bound);
	Primes primes(pl, upper_bound);

	return primes.get_ith_prime(seq);
}
