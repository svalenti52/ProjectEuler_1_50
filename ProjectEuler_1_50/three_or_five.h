#pragma once

#include <numeric>
#include <vector>

int three_or_five_sum()
{
	using namespace std;

	vector<int> v;

	for (int ix = 2; ix < 1000; ++ix)
		if (ix % 3 == 0 || ix % 5 == 0)
			v.emplace_back(ix);
	return accumulate(begin(v), end(v), 0);
}
