#pragma once

#include <set>
#include <vector>
#include <numeric>
#include <iostream>

int sum_of_proper_divisors(int n)
{
	std::vector<int> divisors;

	int ub = n / 2 + 1;

	divisors.emplace_back(1);
	for (int number = 2; number < ub; ++number)
		if (n % number == 0)
			divisors.emplace_back(number);
	return std::accumulate(divisors.begin(), divisors.end(), 0);
}

void amicable_lt_10000()
{
	std::set<int> amicable; // automatically eliminate duplicates

	for (int ix = 4; ix < 10'000; ++ix)
	{
		int sopd = sum_of_proper_divisors(ix);
		int comp = sum_of_proper_divisors(sopd);
		if (comp == ix && ix != sopd) {
			std::cout << ix << "-" << sopd << ", " << comp << '\n';
			amicable.insert(ix);
			amicable.insert(sopd);
		}
	}
	
	int sum = std::accumulate(amicable.begin(), amicable.end(), 0);
	std::cout << "Sum Amicable Numbers Less Than 10,000 = " << sum << '\n';
}
