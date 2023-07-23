#pragma once

#include <vector>
#include <iostream>

int factorial(int n)
{
	if (n == 1 || n == 0) return 1;

	return n * factorial(n - 1);
}

bool qualifying_number(int number)
{
	using namespace std;

	vector<int> digits;
	const int _10 = 10;
	int x = number;

	while (x != 0)
	{
		int digit = x % _10;
		digits.emplace_back(digit);
		x /= 10;
	}

	int sum_factorial = 0;
	for (int i : digits)
		sum_factorial += factorial(i);

	if (number == sum_factorial)
		return true;

	return false;
}

void digit_factorial()
{
	using namespace std;

	vector<int> vi;

	for (int ix = 10; ix < 10'000'000; ++ix)
	{
		if (qualifying_number(ix))
		{
			vi.emplace_back(ix);
		}
	}

	for (int x : vi)
		cout << x << ", ";
	cout << '\n';

	int sum = accumulate(vi.begin(), vi.end(), 0);

	cout << "Sum of Digit Factorials is = " << sum << '\n';
}
