#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <numeric>

// not accepted as answer 240559 (54748, 92727, 93084)
// not accepted as answer 248860 (4150, 4151, 54748, 92727, 93084)
// it was because there is a 6 digit number with the property!

int digit_5_power(int x)
{
	int sum_5 = 0;
	while (x != 0)
	{
		int y = x % 10;
		y = pow(y, 5);
		sum_5 += y;
		x /= 10;
	}

	return sum_5;
}

void digit_5_powers()
{
	using namespace std;
	vector<int> matching;

	for (int ix = 2; ix < 400'000; ++ix)
	{
		if (ix == digit_5_power(ix))
			matching.emplace_back(ix);
	}

	int sum = accumulate(matching.begin(), matching.end(), 0);

	for (int ans : matching)
		cout << ans << ", ";
	cout << '\n';

	cout << "Sum of 5 digit power sums matching decimal representation = " << sum << '\n';

}
