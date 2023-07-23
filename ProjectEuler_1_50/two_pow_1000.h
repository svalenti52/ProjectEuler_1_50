#pragma once
#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>

using u64 = uint64_t;
using s64 = int64_t;
using namespace std;

void two_to_1000_digit_sum()
{
	// have to use boost/multiprecision package or equivalent
	s64 x = static_cast<s64>(pow(2, 1000));
	s64 div = 1'000'000'000'000'000'000;
	// vector<u64> digits;

	cout << "2^1000 = " << x << '\n';

	//while (div != 0)
	//{
	//	u64 digit = x / div;
	//	x = x % div;
	//	digits.emplace_back(digit);
	//	div /= 10;
	//}

	//u64 sum = accumulate(digits.begin(), digits.end(), 0LL);

	//cout << "Sum of Digits of 2^1000 = " << sum << '\n';
}
