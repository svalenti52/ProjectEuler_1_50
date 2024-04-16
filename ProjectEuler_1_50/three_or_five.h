#pragma once

#include <numeric>
#include <vector>
#include <iostream>
#include <ranges>
#include "../repos/Utilities/Utilities/conventions.h"

void three_or_five_sum_1()
{
	using namespace std;

	vector<int> div_by_3_or_5;
	constexpr auto int_range = R::iota_view(2, 1000);

	for (auto integer : int_range)
		if (integer % 3 == 0 || integer % 5 == 0)
			div_by_3_or_5.emplace_back(integer);

	std::cout << "Sum of numbers below 1000 that are divisible by 3 or 5 = "
		<< R::fold_left(div_by_3_or_5, 0, plus()) << '\n';
}
