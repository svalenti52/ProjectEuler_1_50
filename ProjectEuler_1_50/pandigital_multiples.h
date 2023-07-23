#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

int length_of_numbers(std::vector<int>& v)
{
	int total_len = 0;
	for (int x : v)
	{
		while (x != 0)
		{
			x /= 10;
			++total_len;
		}
	}
	return total_len;
}

std::pair<bool, std::string> is_9_pandigital(std::vector<int>&v)
{
	std::string s{""};
	for (int x : v)
	{
		s += std::to_string(x);
	}
	auto found = s.find('0');
	if (found == std::string::npos)
	{
		const std::string digits = "123456789";
		for (char c : digits)
		{
			found = s.find(c);
			if (found == std::string::npos)
				return std::make_pair(false, s);
		}
		std::cout << s << '\n';
		return std::make_pair(true, s);
	}
	else return std::make_pair(false, s);
}

void pandigital_multiples()
{
	using namespace std;
	int pandigital_max = 123'456'789;

	for (int ix = 1; ix <= 10'000; ++ix) // mistakenly limited to 1,000 where the correct integer is between 1,000 and 10,000
	{
		vector<int> pandigital_candidates;
		for (int jx = 1; jx <= 9; ++jx)
		{
			pandigital_candidates.emplace_back(ix*jx);
			int len = length_of_numbers(pandigital_candidates);
			if (len > 9)
			{
				//pandigital_candidates.clear();
				break;
			}
			if (len == 9)
			{
				auto is_9_pan = is_9_pandigital(pandigital_candidates);
				if (is_9_pan.first)
				{
					int pandigital_number = stol(is_9_pan.second, nullptr, 10);
					if (pandigital_number > pandigital_max)
						pandigital_max = pandigital_number;
				}
				break;
			}
		}
	}

	cout << "Maximum 9-Pandigital Number, Product of an Integer with Sequence 1, 2, .., n, then Concatenated = " << pandigital_max << '\n';
}