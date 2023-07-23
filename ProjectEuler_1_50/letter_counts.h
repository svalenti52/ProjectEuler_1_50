#pragma once

#include <vector>
#include <string>

void print(string& s)
{
	std::cout << s << ", ";
}

void letter_counts()
{
	using namespace std;

	vector<string> vs = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	string andd = "and";

	vector<string> tens = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	string hundred = "hundred";

	string onethousand = "onethousand";

	unsigned count = 0;

	for (string s : vs)
	{
		count += s.size();
		print(s);
	}

	for (string s : tens)
	{
		count += s.size();
		print(s);
		for (int ix = 1; ix <= 9; ++ix)
		{
			string tmp = s + vs[ix];
			count += tmp.size();
			print(tmp);
		}
	}

	for (int ix = 1; ix <= 9; ++ix)
	{
		string tmp = vs[ix] + hundred;
		count += tmp.size();
		print(tmp);
		for (int jx = 1; jx <= 19; ++jx)
		{
			string tmp2 = tmp + andd + vs[jx];
			count += tmp2.size();
			print(tmp2);
		}

		for (string s : tens)
		{
			string tmp3 = tmp + andd + s;
			count += tmp3.size();
			print(tmp3);
			for (int jx = 1; jx <= 9; ++jx)
			{
				string tmp4 = tmp3 + vs[jx];
				count += tmp4.size();
				print(tmp4);
			}
		}
	}
	count += onethousand.size();
	print(onethousand);

	cout << "\nTotal letter count for 1 - 1000 inclusive = " << count << '\n';
}
