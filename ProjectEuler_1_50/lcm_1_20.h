#pragma once

#include <vector>
#include <numeric>

int lcm_1_20()
{
	using namespace std;

	vector<int> v(20, 0);
	iota(begin(v), end(v), 1);

	int lcm_nr = 1;
	for (int x : v)
		lcm_nr = lcm(lcm_nr, x);
	return lcm_nr;
}
