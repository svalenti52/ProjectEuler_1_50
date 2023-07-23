#pragma once
#include <cmath>
#include <iostream>

int special_pythagorean_triple(int target)
{
	bool found = false;
	int a = 0;
	int b = 0;
	int c = 0;
	for (int ix = 1; ix < target && !found; ++ix)
		for (int jx = ix; jx < target && !found; ++jx)
		{
			int h_sqr = ix * ix + jx * jx;
			double x = sqrt(h_sqr);
			if (x - floor(x) == 0)
			{
				c = static_cast<int>(x);
				if (ix + jx + c == target)
				{
					a = ix;
					b = jx;
					found = true;
				}
			}
		}
	cout << a << ", " << b << ", " << c << '\n';
	return a * b * c;
}
