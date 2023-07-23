#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "..\..\..\boost_1_79_0\boost\tokenizer.hpp"

int letter_score_(string& s)
{
	int score = 0;
	for (char c : s)
		score += c - 'A' + 1;
	return score;
}

void coded_triangle_numbers()
{
	using namespace std;
	auto triangle_number_generator = [](int x) {return (x * (x+1))/2;};

	vector<int> triangle_numbers;
	vector<string> vs;

	ifstream words("words.txt", ios::in);
	if (!words.is_open())
	{
		cout << "unable to open file words.txt" << '\n';
		return;
	}
	string word;
	words >> word;

	using tokenizer = boost::tokenizer<boost::char_separator<char>>;
	boost::char_separator<char> sep(",\"");
	tokenizer tokens(word, sep);
	for (tokenizer::iterator tok_iter = tokens.begin();
		tok_iter != tokens.end(); ++tok_iter)
		vs.emplace_back(*tok_iter);

	for (int ix = 0; ix < 1'000; ++ix)
		triangle_numbers.emplace_back(triangle_number_generator(ix));

	int count = 0;

	for (string s : vs)
	{
		int score = letter_score_(s);
		auto tri_it = find(triangle_numbers.begin(), triangle_numbers.end(), score);
		if (tri_it != triangle_numbers.end())
			++count;
	}

	cout << "Coded Triangle Number Word Count = " << count << '\n';
}
