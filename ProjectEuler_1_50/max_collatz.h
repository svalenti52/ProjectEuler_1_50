#pragma once
#include <cstdint>
#include <tuple>
#include <vector>
#include <numeric>
#include <iostream>

using u64 = uint64_t;
using namespace std;

auto collatz_sequence_count(int number)
{
    auto even([](uint64_t z) { return z % 2 == 0; });
    uint64_t x = number;
    int y = 1;

    while (x != 1)
    {
        even(x) ? (x /= 2) : (x = 3 * x + 1);
        ++y;
    }
    return std::make_tuple(y, number);
}

u64 max_collatz_sequence_at()
{
    vector<u64> v(1'000'000, 0);
    iota(begin(v), end(v), 0LL);
    v[0] = 1; // effectively removes 0 from consideration while keeping numbers aligned with index

    u64 max_count = 0;
    u64 index_of_max_count = 0;

    for (u64 x : v)
    {
        auto [count, number] = collatz_sequence_count(x);
        if (count > max_count)
        {
            max_count = count;
            index_of_max_count = number;
        }
    }

    cout << "Maximum Collatz Count " << max_count << " at Number " << index_of_max_count << '\n';
    return index_of_max_count;
}
