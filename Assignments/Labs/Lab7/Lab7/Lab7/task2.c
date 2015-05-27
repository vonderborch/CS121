#include "lab7.h"
#include "task2.h"

int task2_main (void)
{
	int option = 0, task_state = 0;
	int year = 0;
	double money = 0;

	while (task_state >= 0)
	{
		option = display_standard_menu ("Lab 7, Task 2: Main Menu",
			"1. Calculate Revenue\n2. Predict Year\n3. Exit Task 2",
			'i', 3, 1);
		if (option == 1)
		{
			printf ("Year to Calculate Revenue? ");
			scanf (" %d", &year);
			money = revenue (year);
			printf ("Revenue for %d is $.2%lf million.\n\n", year, money);
			system ("pause");
		}
		else if (option == 2)
		{
			printf ("Revenue? ");
			scanf (" %lf", &money);
			year = predict (money);
			printf ("Revenue will pass $%.2lf million in %d.\n\n", money, year);
			system ("pause");
		}
		else if (option == 3)
		{
			task_state = -1;
		}
	}

	return 0;
}

double revenue (int year)
{
	int money = 203.265 * pow (1.071, (year - 1984));
	return money;
}

int predict (double money)
{
	int year = 1984;
	double temp_money = 0;
	FILE* outfile = NULL;
	outfile = fopen ("task2_output.dat", "w");
	while (money > temp_money)
	{
		temp_money = 203.265 * pow (1.071, (year - 1984));
		fprintf (outfile, "Year %d Revenue: $%.2lf\n", year, temp_money);
		year++;
	}
	year + 1984;
	fclose (outfile);
	return year;
}
