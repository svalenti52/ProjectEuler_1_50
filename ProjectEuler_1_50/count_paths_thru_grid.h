#pragma once

#include <vector>
#include <iostream>

using namespace std;
using u64 = uint64_t;

static u64 path_count = 0;

void show_grid_count()
{
	cout << "Grid Path Count = " << path_count << '\n';
	path_count = 0;
}

void traverse_grid(int h_idx, int v_idx)
{
	//vector<vector<int>> vi;

	//int state = 0;
	//for (int ix = 0; ix < 20; ++ix)
	//{
	//	vector<int> t;
	//	for (int jx = 0; jx < 20; ++jx)
	//	{
	//		t.emplace_back(state);
	//		++state;
	//	}
	//	vi.emplace_back(t);
	//}

	const int grid_size = 20;

	if (h_idx == grid_size && v_idx == grid_size)
		++path_count;
	else
	{
		if (h_idx < grid_size)
		{
			++h_idx;
			traverse_grid(h_idx, v_idx);
			--h_idx;
		}
		if (v_idx < grid_size)
		{
			++v_idx;
			traverse_grid(h_idx, v_idx);
		}
	}
}
