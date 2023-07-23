//
// Created by svalenti on 7/2/2022.
//

#ifndef PROJECTEULER_QUADRATIC_PRIMES_H
#define PROJECTEULER_QUADRATIC_PRIMES_H

#include <iostream>
#include "../repos/MonteCarlo/MonteCarlo/Primes.h"

using u64 = uint64_t;

void longest_sequence_primes()
{
    Primes_List pl(50'000);

    int max_len = 0;
    int max_a = 0;
    int max_b = 0;

    for (int a = -999; a < 1000; ++a)
    {
        for (int b = -1000; b<=1000; ++b)
        {
            int n = 0;
            bool prime_found = true;

            while (prime_found)
            {
                int value = n*n+a*n+b;
                value = abs(value);
                if (pl.is_prime(value))
                    ++n;
                else
                {
                    prime_found = false;
                    if (n>max_len)
                    {
                        max_len = n;
                        max_a = a;
                        max_b = b;
                    }
                }
            }
        }
    }
    std::cout << "Max Sequence of Primes = " << max_len
    << ", Coefficients A = " << max_a << " and B = " << max_b << '\n';
    std::cout << "Product of Maximum Prime Sequence Coefficients = " << max_a * max_b << '\n';
}

#endif //PROJECTEULER_QUADRATIC_PRIMES_H
