#pragma once

#include <vector>
#include "..\..\MonteCarlo\MonteCarlo\Primes.h"


void primes_circular()
{
	using namespace std;
	const int ub = 1'000'000;
	vector<int> circular_primes;
	Primes_List pl(ub);
	Primes primes(pl, ub);
	
	for (int ix = 0; ix <= primes.get_last_index(); ++ix)
	{
		bool all_prime = true;
		int cand_circ_prime = primes.get_ith_prime(ix);
		//cout << cand_circ_prime << ", ";
		string orig_s = to_string(cand_circ_prime);
		//vector<char> vc;
		//for (char c : orig_s)
		//	vc.push_back(c);
		// cout << orig_s << "' ";
		string s = orig_s;
		vector<int> cand_circ_primes{cand_circ_prime};
		while (true)
		{
			if (s.size() == 1);
			else rotate(s.begin(), s.begin() + 1, s.end());
			if (s == orig_s)
				break;
			int x = stol(s, nullptr, 10);
			// cout << x << "' ";
			if (!pl.is_prime(x))
			{
				all_prime = false;
				break;
			}
		}
		if (all_prime)
		{
			for (int p : cand_circ_primes)
				circular_primes.emplace_back(p);
		}
	}
	for (int p : circular_primes)
		cout << p << ", ";
	cout << '\n';
	cout << "Circular Primes Size = " << circular_primes.size() << '\n';
}
