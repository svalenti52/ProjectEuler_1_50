#pragma once
#include <cstdint>
#include "..\..\MonteCarlo\MonteCarlo\Primes.h"

using u64 = uint64_t;

u64 sum_primes_lt_2M()
{
	Primes_List pl(2'000'000);
	u64 sum = 0;
	for (int ix = 0; ix < 2'000'000; ++ix)
	{
		if (pl.is_prime(ix))
			sum += ix;
	}
	return sum;
}
