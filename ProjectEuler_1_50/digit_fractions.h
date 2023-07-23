#pragma once

#include <vector>
#include <iostream>
#include <tuple>
#include <numeric>
#include "../repos/MonteCarlo/MonteCarlo/Combinatorics.h"

using namespace std;

int to_int_base10(vector<int>& v)
{
	int number = 0;
	int size_dec = pow(10, v.size()-1);
	for (int x : v)
	{
		number += x * size_dec;
		size_dec /= 10;
	}
	return number;
}

bool qualified_cancelled_fraction(vector<int>& v1, vector<int>& v2)
{
	if (v1 != v2)
	{
		if (v1[0] != v2[0] && v1[0] != v2[1] && v1[1] != v2[0] && v1[1] != v2[1])
			return false;

		int number1 = to_int_base10(v1);
		int number2 = to_int_base10(v2);
		double rational = double(number1) / double(number2);
		// cout << " -> " << rational << " <- ";
		if (v1[0] == v2[1])
		{
			if (double(v1[1]) / double(v2[0]) == rational)
			{
				//cout << '+';
				return true;
			}
		}
		if (v1[1] == v2[0])
		{
			if (double(v1[0]) / double(v2[1]) == rational)
			{
				//cout << '=';
				return true;
			}
		}
		if (v1[0] == v2[0])
		{
			if (double(v1[1]) / double(v2[1]) == rational)
			{
				//cout << '@' << ' ' << number1 << ' ' << number2;
				return true;
			}
		}
		if (v1[1] == v2[1])
		{
			if (double(v1[0]) / double(v2[0]) == rational)
			{
				//cout << '$';
				return true;
			}
		}
	}

	return false;
}

void digit_fractions()
{	
	vector<int> symbols{1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> permutation;
	vector<vector<int>> permutations;
	vector<pair<int, int>> answers;

	create_combinatorial_element_set<int>(symbols, permutations, permutation, 0, 2, [](vector<int>& v) {return true;}, permutations_without_repetition<int>);

	for (vector<int>& vi1: permutations)
	{
		for (vector<int>& vi2 : permutations)
		{
			if (qualified_cancelled_fraction(vi1, vi2) && to_int_base10(vi1) < to_int_base10(vi2))
			{
				answers.emplace_back(make_pair(to_int_base10(vi1), to_int_base10(vi2)));
			}
		}
	}
	for (pair<int, int>& p : answers)
		cout << "Fraction = " << p.first << '/' << p.second << '\n';

	int numerator = 1;
	int denominator = 1;
	for (auto p : answers)
	{
		numerator *= p.first;
		denominator *= p.second;
	}
	
	int gcd_p = gcd(numerator, denominator);

	cout << "Reduced Denominator of Fractions Product = " << denominator / gcd_p << '\n';
}
