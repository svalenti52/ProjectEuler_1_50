#pragma once

#include <vector>
#include <iostream>

using u64 = uint64_t;

void tri_pen_hex()
{
	using namespace std;
	vector<u64> triangle;
	vector<u64> pentagon;
	vector<u64> hexagon;

	auto tri_gen = [&triangle](int max) {for (u64 ix = 1; ix < max; ++ix) triangle.emplace_back(ix*(ix+1)/2); };
	auto pen_gen = [&pentagon](int max) {for (u64 ix = 1; ix < max; ++ix) pentagon.emplace_back(ix * (3*ix - 1) / 2); };
	auto hex_gen = [&hexagon](int max) {for (u64 ix = 1; ix < max; ++ix) hexagon.emplace_back(ix * (2*ix - 1)); };

	tri_gen(1'000'000);
	pen_gen(100'000);
	hex_gen(100'000);

	u64 number = 0;

	for (u64 t : triangle)
	{
		if (t <= 40755) continue;
		auto pentagonal_it = find(pentagon.begin(), pentagon.end(), t);
		auto hexagonal_it = find(hexagon.begin(), hexagon.end(), t);
		if (pentagonal_it == pentagon.end() || hexagonal_it == hexagon.end()) continue;
		cout << t << '\n';
		number = t;
		break;
	}

	cout << "Next Number Qualifying = " << number << '\n';
}
