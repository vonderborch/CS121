
#include "pa4t2.h"

int int_input (void)
{
	int temp_value = 0;
	scanf("%d", &temp_value);
	return temp_value;
}

int prompt_month (void)
{
	int temp_value = 0;
	printf ("Enter Month as a Number (Jan = 1, Dec = 12): ");
	temp_value = int_input ();
	return temp_value;
}

int prompt_day (void)
{
	int temp_value = 0;
	printf ("Enter Day: ");
	temp_value = int_input ();
	return temp_value;
}

int prompt_year (void)
{
	int temp_value = 0;
	printf ("Enter Year: ");
	temp_value = int_input ();
	return temp_value;
}

int is_leap_year (int year)
{
	int temp_value = 0, temp_value_b = 0, is_leap = 0;

	temp_value = year%4;

	if (temp_value == 0)
	{
		is_leap = 1;
		temp_value = year%100;
		temp_value_b = year%400;
		if (temp_value == 0 && temp_value_b != 0)
		{
			is_leap = 0;
		}
	}

	return is_leap;
}

int calculate_day_number (int month, int day, int is_leap_year)
{
	int day_number = 0, pre_month_days = 0;

	// January
	if (month > 1)
	{
		pre_month_days += 31;
	}
	// February
	if (month > 2)
	{
		pre_month_days += 28;
		if (is_leap_year == 1)
		{
			pre_month_days += 1;
		}
	}
	// March
	if (month > 3)
	{
		pre_month_days += 31;
	}
	// April
	if (month > 4)
	{
		pre_month_days += 30;
	}
	// May
	if (month > 5)
	{
		pre_month_days += 31;
	}
	// June
	if (month > 6)
	{
		pre_month_days += 30;
	}
	// July
	if (month > 7)
	{
		pre_month_days += 31;
	}
	// August
	if (month > 8)
	{
		pre_month_days += 31;
	}
	// September
	if (month > 9)
	{
		pre_month_days += 30;
	}
	// October
	if (month > 10)
	{
		pre_month_days += 31;
	}
	// Novermber
	if (month > 11)
	{
		pre_month_days += 30;
	}

	// Calculate day number and return it
	day_number = pre_month_days + day;
	return day_number;
}

int display_day_number (int month, int day, int year, int day_number)
{
	printf ("The Day # for %d/%d/%d is %d\n\n", month, day, year, day_number);
	return 0;
}
