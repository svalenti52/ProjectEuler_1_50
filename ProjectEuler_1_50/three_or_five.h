#pragma once

#include <numeric>
#include <vector>
#include <iostream>
#include <ranges>

void three_or_five_sum()
{
	using namespace std;
	using namespace ranges;

	vector<int> div_by_3_or_5;
	constexpr auto int_range = iota_view(2, 1000);

	for (auto integer : int_range)
		if (integer % 3 == 0 || integer % 5 == 0)
			div_by_3_or_5.emplace_back(integer);

	std::cout << "Sum of numbers below 1000 that are divisible by 3 or 5 = "
		<< fold_left(div_by_3_or_5, 0, plus()) << '\n';
}
