#pragma once

#include <string>
#include "..\..\MonteCarlo\MonteCarlo\Primes.h"
using namespace std;
using u64 = uint64_t;

void four_digit_3_prime_seq()
{
	Primes_List pl(10'000);
	Primes primes(pl, 10'000);

	int p_index_begin = 0;
	while (true)
	{
		u64 p = primes.get_ith_prime(p_index_begin);
		if (p / 1000 != 0) // this loop gets first 4-digit prime
			break;
		++p_index_begin;
	}

	for (int pix = p_index_begin; pix <= primes.get_last_index(); ++pix) {
		for (u64 diff = 2; diff < 10'000; ++diff)
		{
			u64 P1 = primes.get_ith_prime(pix);  // this is prime
			u64 P2 = P1 + diff;  // check if this is prime
			u64 P3 = P2 + diff;  // check if P3 >= 10,000 (P3 is a 5-digit number) and if it is prime

			if (P3 / 10'000 != 0) continue;

			if (!(pl.is_prime(P2) && pl.is_prime(P3)))
				continue;

			string s1 = to_string(P1);
			string s2 = to_string(P2);
			string s3 = to_string(P3);

			sort(s1.begin(), s1.end()); // get strings s1, s2, s3 in same order
			sort(s2.begin(), s2.end()); // if permutations of each other
			sort(s3.begin(), s3.end()); // then s1 == s2 == s3

			if (s1 == s2 && s2 == s3)
				cout << P1 << ", " << P2 << ", " << P3 << '\n';
		}
	}
}
