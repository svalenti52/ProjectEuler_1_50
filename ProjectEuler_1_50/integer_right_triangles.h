#pragma once

#include <vector>
#include <iostream>

void integer_right_triangles()
{
	int max_nr_solutions = 0;
	int max_circ = 0;

	for (int circ = 3; circ <= 1000; ++circ)
	{
		int nr_solutions = 0;
		vector<int> circumference;
		for (int jx = 1; jx <= circ/2; ++jx)
		{
			for (int kx = 1; kx <= circ / 2; ++kx)
			{

				int o_side = circ - jx - kx;
				if (jx * jx + kx * kx == o_side * o_side)
				{
					circumference.emplace_back(circ);
					++nr_solutions;
				}
			}
		}
		if (nr_solutions > max_nr_solutions)
		{
			max_nr_solutions = circumference.size();
			max_circ = circ;
		}
	}

	cout << "Max solutions = " << max_nr_solutions << " for circumference = " << max_circ << '\n';
}
