#pragma once

#include <vector>
#include <charconv>

void champernownes()
{
	using namespace std;
	vector<int> ans {0, 0, 0, 0, 0, 0, 0};

	string s;

	for (int ix = 0; ix < 300'000; ++ix)
	{
		string c = to_string(ix);
		s.append(c);
	}
	cout << "size of number = " << s.size() << '\n';
	

	from_chars(&s[1], (&s[1]+1), ans[0]);
	from_chars(&s[10], (&s[10]+1), ans[1]);
	from_chars(&s[100], (&s[100]+1), ans[2]);
	from_chars(&s[1'000], (&s[1'000]+1), ans[3]);
	from_chars(&s[10'000], (&s[10'000]+1), ans[4]);
	from_chars(&s[100'000], (&s[100'000]+1), ans[5]);
	from_chars(&s[1'000'000], (&s[1'000'000]+1), ans[6]);

	int prod = accumulate(ans.begin(), ans.end(), 1, multiplies());

	cout << prod << '\n';
}
