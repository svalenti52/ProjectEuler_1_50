#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using u64 = uint64_t;

bool test_range(vector<int>::iterator b, vector<int>::iterator e, int divisor)
{
	int number = *b;
	for (auto ix = b + 1; ix != e; ++ix)
		number = 10 * number + *ix;

	if (number % divisor == 0) return true;
	return false;
}

u64 construct_number(vector<int>& vi)
{
	u64 number = 0;
	for (int x : vi)
		number = number * 10 + x;
	return number;
}

void substring_divisibility()
{
	using namespace std;

	vector<int> symbols = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<u64> triangle_pandigital_prime_div;
	
	int nr_with_property = 0;

	do
	{
		if (!test_range(symbols.begin() + 1, symbols.begin() + 4, 2)) continue;
		if (!test_range(symbols.begin() + 2, symbols.begin() + 5, 3)) continue;
		if (!test_range(symbols.begin() + 3, symbols.begin() + 6, 5)) continue;
		if (!test_range(symbols.begin() + 4, symbols.begin() + 7, 7)) continue;
		if (!test_range(symbols.begin() + 5, symbols.begin() + 8, 11)) continue;
		if (!test_range(symbols.begin() + 6, symbols.begin() + 9, 13)) continue;
		if (!test_range(symbols.begin() + 7, symbols.end(), 17)) continue;
		++nr_with_property;
		triangle_pandigital_prime_div.emplace_back(construct_number(symbols));
	} while (next_permutation(symbols.begin(), symbols.end()));

	cout << "SubString Divisibility Count = " << nr_with_property << '\n';

	for (u64 u : triangle_pandigital_prime_div)
		cout << u << ", ";
	cout << '\n';

	u64 sum = accumulate(triangle_pandigital_prime_div.begin(), triangle_pandigital_prime_div.end(), 0LL);

	cout << "SubString Divisibility Sum = " << sum << '\n';
}
