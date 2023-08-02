#pragma once

#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>

using u64 = uint64_t;

void fibo_even_sum_2()
{
	using namespace std;
	using namespace ranges;

	const int bound = 4'000'000;

	vector<int> fibo_seq{ 1, 2 };
	vector<int> fibo_even{ 2 }; // already have 2 in the initial vector

	for (int ix = 2; ix <= bound; ++ix)
	{
		int fibo = fibo_seq[ix - 2] + fibo_seq[ix - 1];
		if (fibo > bound)
			break;
		else
			fibo_seq.emplace_back(fibo);
		if (fibo % 2 == 0)
			fibo_even.emplace_back(fibo);
	}

	std::cout << "Sum of fibo_even fibonnci sequence <= 4,000,000 = "
		<< fold_left(fibo_even, 0, plus()) << '\n';
}
