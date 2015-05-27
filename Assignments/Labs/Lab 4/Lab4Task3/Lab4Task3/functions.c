
#include "pa4t3.h"


int read_number (FILE *infile)
{
	int temp_value = 0;
	fscanf (infile, "%d", &temp_value);
	return temp_value;
}

int calculate_total_minutes (int weekday_minutes, int night_minutes, int weekend_minutes)
{
	int total_minutes = weekday_minutes + night_minutes + weekend_minutes;
	return total_minutes;
}

double calculate_monthly_bill (int weekday_minutes, int night_minutes, int weekend_minutes)
{
	double monthly_bill = 39.99;
	if (weekday_minutes > 600)
	{
		weekday_minutes -= 600;
		monthly_bill += weekday_minutes * 0.40;
	}
	return monthly_bill;
}

double calculate_average_minute (double monthly_bill, int total_minutes)
{
	double average_cost = monthly_bill / total_minutes;
	return average_cost;
}

double calculate_taxes (double monthly_bill)
{
	double taxes = monthly_bill * 0.0525;
	return taxes;
}
double calculate_final_bill (double monthly_bill, double taxes)
{
	double final_bill = monthly_bill + taxes;
	return final_bill;
}

void print_value (FILE *outfile, char header[], int number)
{
	fprintf (outfile, "%s%d\n", header, number);
	return;
}

void print_double (FILE *outfile, char header[], double number)
{
	fprintf (outfile, "%s%.2lf\n", header, number);
	return;
}