#pragma once

// sundays_first_of_month.h

enum day
{
	sunday, // = 0
	monday,
	tuesday,
	wednesday,
	thursday,
	friday, // = 5
	saturday // = 6
};

day operator ++ (day& d)
{
	if (saturday) return sunday;
	++d;
	return d;
}


enum month
{
	jan,
	feb,
	mar,
	apr,
	may,
	jun,
	jul,
	aug,
	sep,
	oct,
	nov,
	dec
};

void sundays_1st_of_month_century20()
{
	const int first_day_of_20th_century = monday; // fake begin of century
	int day_tracker = first_day_of_20th_century;
	int nr_days_sunday_1st_day_of_month = 0;

	for (int year = 1900; year <= 2000; ++year)
	{
		if (year != 1900)
			std::cout << "Year is " << year << ", "; // skip 1900, 20th century begins 1-Jan-1901
		for (int mnth = jan; mnth <= month::dec; ++mnth)
		{
			int days_per_month = 31;
			if (mnth == apr || mnth == jun || mnth == sep || mnth == nov)
				days_per_month = 30;
			else if (mnth == feb)
			{
				days_per_month = 28;
				if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
						days_per_month = 29;
			}
			for (int days = 1; days <= days_per_month; ++days)
			{
				if (days == 1 && day_tracker == sunday && year != 1900) // don't include 1900 in the 20th century
				{
					++nr_days_sunday_1st_day_of_month;
					std::cout << "*, ";
				}
				++day_tracker;
				day_tracker %= 7;
			}
		}
	}
	std::cout << "\nNumber of Sundays on the First Day of Month for 20th Century (1-Jan-1901 -- 31-Dec-2000) = " << nr_days_sunday_1st_day_of_month << '\n';
}
