
#include "pa4t2.h"

int main (void)
{
	int month = 0, day = 0, year = 0, leap_year = 0, day_number = 0;

	month = prompt_month ();
	day = prompt_day ();
	year = prompt_year ();

	leap_year = is_leap_year (year);

	day_number = calculate_day_number (month, day, leap_year);

	display_day_number (month, day, year, day_number);

	return 0;
}