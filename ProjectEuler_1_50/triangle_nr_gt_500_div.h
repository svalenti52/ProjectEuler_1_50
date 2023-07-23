#pragma once
#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;
using u64 = uint64_t;

tuple<u64, u64> triangle_nr_gt_500_div()
{
	const u64 ub = 20'000;
	tuple<u64, u64> number_first_count_second;

	// creating ub triangle numbers
	vector<u64> triangles(ub, 0);
	for (u64 ix = 1; ix < ub; ++ix)
	{
		u64 tn = 0;
		for (u64 jx = 1; jx <= ix; ++jx)
			tn += jx;
		triangles[ix] = tn;
	}

	// std::cout << "Triangle Number = " << triangles[8] << '\n';

	for (u64 ix = 100; ix < ub; ++ix)
	{
		u64 count = 0;
		bool square = false;
		double ub_sqrt = sqrt(triangles[ix]);
		if (ub_sqrt - floor(ub_sqrt) == 0) square = true;
		u64 ub_sqrt_i = static_cast<u64>(ub_sqrt);

		for (u64 jx = 1; jx <= ub_sqrt_i; ++jx)
			if (triangles[ix] % jx == 0)
			{
				if (jx == ub_sqrt_i && square)
					++count;
				else
					count += 2;
			}

		if (count > 500)
		{
			get<0>(number_first_count_second) = triangles[ix];
			get<1>(number_first_count_second) = count;
			break;
			//std::cout << "Triangle Number Divisor Count = " << count << "  for number " << triangles[ix] << endl;
		}
	}
	return number_first_count_second;
}
