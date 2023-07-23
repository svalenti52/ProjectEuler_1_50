#pragma once

//#include "..\repos\MonteCarlo\MonteCarlo\Combinatorics.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

void lex_order()
{
	using namespace std;

	string sym("0123456789");

	vector<string> lexorder;

	do
	{
		lexorder.emplace_back(sym);
	} while (next_permutation(sym.begin(), sym.end()));

	cout << "One Millionth Permutation " << lexorder[999'999] << '\n';
}
