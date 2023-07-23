#pragma once
#include <cstdint>
#include <tuple>
#include <vector>
#include <numeric>

using namespace std;
using u64 = uint64_t;

u64 sum_sqr_diff(const u64 sz)
{
	vector<u64> seq(sz, 0);
	vector<u64> seq_sqr;

	iota(begin(seq), end(seq), 1);

	seq_sqr = seq;

	for (u64& s : seq_sqr)
		s = s * s;

	u64 sum = accumulate(begin(seq), end(seq), 0);

	u64 sum_sqr = accumulate(begin(seq_sqr), end(seq_sqr), 0);

	return sum * sum - sum_sqr;
}
