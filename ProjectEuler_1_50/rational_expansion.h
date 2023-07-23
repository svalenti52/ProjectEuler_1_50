#pragma once

#include <vector>
#include <numeric>
#include <iostream>
#include <cmath>
#include <set>
#include <tuple>

void rational_expansion()
{
	using namespace std;

	vector<int> divisor(998, 0);
	iota(divisor.begin(), divisor.end(), 2);
	vector<int> quotient;
	set<pair<int, int>> quot_rem;
	// set<int> quot;

	int max_count = 0;
	int max_divisor = 0;

	for (int d : divisor)
	{
		cout << d << ". ";
		int multiplier_carry = 10;
		//int dividend = 1 * multiplier_carry;
		// auto result = div(dividend, d);
		
		int rem_w_carry = 1 * multiplier_carry;

		int insert_count = 0;
		 
		for (int ix = 0; ix < 1000; ++ix)
		{
			auto result = div(rem_w_carry, d);
			auto result_insert = quot_rem.insert(make_pair(result.quot, result.rem));
			//auto result_insert = quot.insert(result.quot);
			if (!result_insert.second)
				break;
			else
				++insert_count;
			quotient.emplace_back(result.quot);
			rem_w_carry = result.rem * multiplier_carry;
		}
		//for (int expansion : quotient)
		//	cout << expansion << ", ";
		cout << insert_count << '\n';
		quotient.clear();
		quot_rem.clear();

		if (insert_count > max_count)
		{
			max_count = insert_count;
			max_divisor = d;
		}
	}

	cout << "\n\nMaximum Count = " << max_count << "  For Divisor = " << max_divisor << '\n';
}
