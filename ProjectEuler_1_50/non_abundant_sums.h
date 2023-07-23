//
// Created by svalenti on 7/2/2022.
//

#ifndef PROJECTEULER_NON_ABUNDANT_SUMS_H
#define PROJECTEULER_NON_ABUNDANT_SUMS_H

#include <vector>
#include <numeric>

using namespace std;

void non_abundant_sums()
{
    const int upper_bound = 28124;
    vector<bool> as(upper_bound, false);
    for (int ix = 0; ix < upper_bound; ++ix)
    {
        vector<int> divisors;
        if (ix == 0) as[ix] = false;
        else
        {
            divisors.emplace_back(1);
            for (int jx = 2; jx < ix/2+1; ++jx)
                if (ix % jx == 0)
                    divisors.emplace_back(jx);
            int sum = accumulate(divisors.begin(), divisors.end(), 0);
            if (sum > ix)
                as[ix] = true;
        }
        divisors.clear();
    }

    vector<int> nas;
    for (int ix = 1; ix < 24; ++ix)
        nas.emplace_back(ix);

    for (int ix = 24; ix < upper_bound; ++ix)
    {
        bool not_both_as = true;
        for (int jx = 1; jx<ix/2+1; ++jx)
        {
            int diff = ix-jx;
            if (as[jx] && as[diff])
            {
                not_both_as = false;
                break;
            }
        }
        if (not_both_as)
            nas.emplace_back(ix);
    }

    int sum_nas = accumulate(nas.begin(), nas.end(), 0);

    cout << "Sum of Not Sum of two AS = " << sum_nas << '\n';
//    for (int x : nas)
//        if ( x > 2000)
//        cout << x << ", ";
//    cout << '\n';
//    cout << "Not sum of two AS count = " << nas.size() << '\n';
}

#endif //PROJECTEULER_NON_ABUNDANT_SUMS_H
