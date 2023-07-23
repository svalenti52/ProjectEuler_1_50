#pragma once

#include "../../MonteCarlo/MonteCarlo/Primes.h"

int largest_pal_3x3_product()
{
	int largest_pal = 0;

	for (int ix = 100; ix <= 999; ++ix)
		for (int jx = 100; jx <= 999; ++jx)
		{
			int is_pal = ix * jx;
			if (is_numeric_calc_palindrome(is_pal) && is_pal > largest_pal)
				largest_pal = is_pal;
		}
	return largest_pal;
}
