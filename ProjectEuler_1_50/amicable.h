#pragma once

#include <set>
#include <vector>
#include <numeric>
#include <iostream>
#include <ranges>
#include "../repos/Utilities/Utilities/print_containers.h"

int sum_of_proper_divisors(int n)
{
	using namespace std;
	using namespace ranges;
	std::vector<int> divisors;

	int ub = n / 2 + 1;

	divisors.emplace_back(1);
	for (int divisor = 2; divisor < ub; ++divisor)
		if (n % divisor == 0)
			divisors.emplace_back(divisor);
	return fold_left(divisors, 0, plus());
}

void amicable_lt_10000()
{
	using namespace std;
	using namespace ranges;

	set<int> amicable; // automatically eliminate duplicates

	for (int sopd_1 = 4; sopd_1 < 10'000; ++sopd_1)
	{
		int sopd_2 = sum_of_proper_divisors(sopd_1);
		if (sopd_1 == sopd_2) continue;
		if (sopd_1 == sum_of_proper_divisors(sopd_2)) {
			amicable.insert(sopd_2);
			amicable.insert(sopd_1);
		}
	}

	print_::space_sep_elements(amicable);

	int sum = fold_left(amicable, 0, plus());

	cout << "Sum Amicable Numbers Less Than 10,000 = " << sum << '\n';
}
