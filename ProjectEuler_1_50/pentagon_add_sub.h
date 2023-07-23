#pragma once

#include <vector>
#include <iostream>

using u64 = uint64_t;

std::vector<u64> pentagonal_numbers;

bool is_pentagonal_number(u64 number) {
    /////////////////////////////////////////////////////////////////////
    // the u64 treatment
    auto integral = (sqrt(1.0 + 24.0 * static_cast<double>(number)) + 1) / 6;
    if (integral - floor(integral) == 0)
        return true;
    return false;
}

void generate_pentagonal_numbers(u64 max_number)
{
    for (u64 ix = 1; ix <= max_number; ++ix)
        pentagonal_numbers.emplace_back((3 * ix - 1) * ix / 2);
}

void pentagon_add_sub()
{
	using namespace std;

    generate_pentagonal_numbers(1'000'000);

    u64 min_diff = 10'000'000;

    for (u64 ix = 1; ix < 60'000; ++ix)
        for (u64 jx = 1; jx < 60'000; ++jx)
        {
            u64 pn_sum = pentagonal_numbers[ix - 1] + pentagonal_numbers[jx - 1];
            if (!is_pentagonal_number(pn_sum))
                continue;
            if (ix == jx)
                continue;
            u64 pn_dif;
            if (ix > jx)
                pn_dif = pentagonal_numbers[ix - 1] - pentagonal_numbers[jx - 1];
            else
                pn_dif = pentagonal_numbers[jx - 1] - pentagonal_numbers[ix - 1];
            if (!is_pentagonal_number(pn_dif))
                continue;
            if (pn_dif < min_diff)
                min_diff = pn_dif;
        }

    pentagonal_numbers.clear();

    cout << "Minimum difference is = " << min_diff << '\n';
}
