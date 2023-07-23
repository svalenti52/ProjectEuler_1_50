#pragma once

#include <vector>
#include <algorithm>

void spiral_diagonal()
{
	using namespace std;

	const int extent = 500;

	vector<int> diff1{ 2 };
	vector<int> diff2{ 4 };
	vector<int> diff3{ 6 };
	vector<int> diff4{ 8 };

	const int diff = 8;

	for (int ix = 1; ix <= extent; ++ix)
	{
		diff1.emplace_back(diff1[ix-1] + diff);
		diff2.emplace_back(diff2[ix-1] + diff);
		diff3.emplace_back(diff3[ix-1] + diff);
		diff4.emplace_back(diff4[ix-1] + diff);
	}

	vector<int> diag1{ 1 };
	vector<int> diag2{ 1 };
	vector<int> diag3{ 1 };
	vector<int> diag4{ 1 };

	for (int ix = 1; ix <= extent; ++ix)
	{
		diag1.emplace_back(diff1[ix - 1] + diag1[ix-1]);
		diag2.emplace_back(diff2[ix - 1] + diag2[ix-1]);
		diag3.emplace_back(diff3[ix - 1] + diag3[ix-1]);
		diag4.emplace_back(diff4[ix - 1] + diag4[ix-1]);
	}

	int sum1 = accumulate(diag1.begin(), diag1.end(), 0);
	int sum2 = accumulate(diag2.begin(), diag2.end(), 0);
	int sum3 = accumulate(diag3.begin(), diag3.end(), 0);
	int sum4 = accumulate(diag4.begin(), diag4.end(), 0);

	int final_total = sum1 + sum2 + sum3 + sum4 - 3; // 1 should included once, not four times!

	//for (int ix : diag4)
	//	cout << ix << ", ";
	//cout << '\n';

	cout << "Sum of Diagonal Spiral is " << final_total << '\n';
}
