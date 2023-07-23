#pragma once

#include "../repos/MonteCarlo/MonteCarlo/Primes.h"

using u64 = uint64_t;

bool truncatable_from_right(Primes_List& pl, u64 p)
{
	while (p != 0)
	{
		if (!pl.is_prime(p)) return false;
		p /= 10;
	}
	return true;
}

bool truncatable_from_left(Primes_List& pl, u64 p)
{
	u64 tmp = p;
	int place = 0;
	tmp /= 10;
	if (tmp == 0) return false;
	while (tmp != 0)
	{
		tmp /= 10;
		++place;
	}

	auto pow_integ =
		[](int b, int e)
		{
			int t = 1;
			for (int x = e; e != 0; --e)
				t *= 10;
			return t;
		};

	while (place >= 1)
	{
		u64 x = p % pow_integ(10, place);
		if (!pl.is_prime(x)) return false;
		--place;
	}
	
	return true;
}

void truncatable_primes()
{
	using namespace std;
	const u64 prime_cap = 1'000'000;
	Primes_List pl(prime_cap);
	Primes primes(pl, prime_cap);
	vector<u64> truncatable;

	for (int ix = 0; ix <= primes.get_last_index(); ++ix)
	{
		u64 prime = primes.get_ith_prime(ix);
		if (truncatable_from_right(pl, prime)  && truncatable_from_left(pl, prime))
			truncatable.emplace_back(prime);
	}

	cout << "\n\n";
	for (u64 p : truncatable)
		cout << p << ", ";
	cout << '\n';

	u64 sum = accumulate(truncatable.begin(), truncatable.end(), 0);
	cout << "Sum of truncatable primes = " << sum << '\n';
}
