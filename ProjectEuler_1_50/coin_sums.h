#pragma once

void coin_sums()
{
	const int target = 200;
	int count = 0;

	for (int _200p = 0; _200p <= 1; ++_200p)
		for (int _100p = 0; _100p <= 2; ++_100p)
			for (int _50p = 0; _50p <= 4; ++_50p)
				for (int _20p = 0; _20p <= 10; ++_20p)
					for (int _10p = 0; _10p <= 20; ++_10p)
						for (int _5p = 0; _5p <= 40; ++_5p)
							for (int _2p = 0; _2p <= 100; ++_2p)
							{
								int _1p = target - (200 * _200p + 100 * _100p + 50 * _50p + 20 * _20p + 10 * _10p + 5 * _5p + 2 * _2p);
								if (_1p >= 0)
									++count;
							}

	cout << "Number of different ways to sum coins to 2 pounds is " << count << '\n';
}
