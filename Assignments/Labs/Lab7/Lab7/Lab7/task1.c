#include "lab7.h"
#include "task1.h"

int task1_main (void)
{
	FILE* infile = NULL, *outfile = NULL;
	int month = 0, year = 0,
		customer_number = 0, hours_used = 0;
	double charge = 0.0, average_cost = 0.0;

	printf ("\nOpening files...");

	infile = fopen ("task1_input.dat", "r");
	outfile = fopen ("task1_output.dat", "w");

	fscanf (infile, " %d", &month);
	fscanf (infile, " %d", &year);
	
	fprintf (outfile, "InternetLite Charges for %d/%d\n\nCustomer # --|-- Hours Used --|-- Total Charge --|-- Average Cost\n", month, year);

	printf ("Calculating Costs...");
	while (!feof (infile))
	{
		fscanf (infile, " %d", &customer_number);
		fscanf (infile, " %d", &hours_used);

		charges (hours_used, &charge, &average_cost);
		fprintf (outfile, "%d\t\t   --|-- %d\t\t\t--|-- $%.2lf\t\t   --|-- $%.2lf\n", customer_number, hours_used, charge, average_cost);
	}

	printf ("Closing files...");

	fclose (infile);
	fclose (outfile);

	printf ("Charges complete!\n");
	system ("pause");

	return 0;
}

void charges (int hours, double *charge, double *average_cost)
{
	int temp_hours = hours;
	double money = 7.99, average = 0.0;
	if (hours > 10)
	{
		temp_hours -= 10;
		money = money + (temp_hours * 1.99);
	}
	average = money / hours;
	money = round_money (money);
	average = round_money (average);
	*charge = money;
	*average_cost = average;
}

double round_money (double money)
{
	money *= 1000;
	money = ceil(money);
	money /= 1000;
	return money;
}