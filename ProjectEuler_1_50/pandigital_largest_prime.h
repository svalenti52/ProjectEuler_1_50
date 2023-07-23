#pragma once

#include <vector>
#include "..\..\MonteCarlo\MonteCarlo\Primes.h"
#include "..\..\MonteCarlo\MonteCarlo\Chronology.h"
#include <algorithm>

using namespace std;
using u64 = uint64_t;

u64 form_number_from_digits(vector<u64>& d)
{
	u64 base_10 = 1;
	u64 number = 0;
	for (u64 x : d)
	{
		number += x * base_10;
		base_10 *= 10;
	}
	return number;
}

void pandigital_largest_prime()
{
	StopWatch s;
	u64 base_10 = 10'000'000;
	Primes_List pl(base_10);
	s.stop();
	vector<u64> digits = { 1, 2 }; 
	vector<u64> prime_candidates;

	for (u64 ix = 3; ix <= 7; ++ix) // 8-digit, 9-digit Pandigital cannot be prime because divisible by 3
	{
		digits.emplace_back(ix);
		do
		{
			u64 x = form_number_from_digits(digits);
			if (pl.is_prime(x))
				prime_candidates.emplace_back(x);
		} while (next_permutation(digits.begin(), digits.end()));

		auto max_pandigital_it = max_element(prime_candidates.begin(), prime_candidates.end());

		if (max_pandigital_it != prime_candidates.end())
			cout << "Maximum " << ix << "-Pandigital Number = " << *max_pandigital_it << '\n';
		else
			cout << "No primes among " << ix << "-Pandigital Numbers" << '\n';
		prime_candidates.clear();
	}
	// oddly enough there are no 8- or 9-pandigital primes!
}