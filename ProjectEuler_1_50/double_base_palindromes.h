#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "../repos/MonteCarlo/MonteCarlo/Primes.h"

void double_base_palindromes()
{
	using namespace std;

	vector<int> vi;

	for (int ix = 1; ix < 1'000'000; ix += 2)
	{
		if (is_numeric_calc_palindrome(ix))
		{
			if (is_numeric_binary_palindrome(ix))
				vi.emplace_back(ix);
		}
	}

	for (int x : vi)
		cout << x << ", ";
	cout << '\n';

	int sum = accumulate(vi.begin(), vi.end(), 0);

	cout << "Double Base Palindrome Sum = " << sum << '\n';
}
