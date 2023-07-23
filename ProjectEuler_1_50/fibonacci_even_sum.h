#pragma once

#include <vector>
#include <numeric>

using u64 = uint64_t;

int fibo_even_sum(int bound)
{
	using namespace std;

	vector<int> fibo_v(2, 0);
	vector<int> even(1, 2);

	iota(begin(fibo_v), end(fibo_v), 1);

	for (int ix = 2; ix <= bound; ++ix)
	{
		int fibo = fibo_v[ix - 2] + fibo_v[ix - 1];
		if (fibo > bound)
			break;
		else
			fibo_v.emplace_back(fibo);
		if (fibo % 2 == 0)
			even.emplace_back(fibo);
	}
	return accumulate(begin(even), end(even), 0);
}
