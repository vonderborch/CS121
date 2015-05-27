#include "lab5t1.h"


void display_message (int message)
{
	if (message == 1)
	{
		printf ("Lab 5, Task 1\n");
	}
	else if (message == 2)
	{
		printf ("Error: Incorrect Use Code. Enter correct Use Code.\n");
	}
	return;
}

int prompt_account_number (void)
{
	int temp_value = 0;
	printf ("User Account Number? ");
	scanf (" %d", &temp_value);
	return temp_value;
}

char prompt_use_code (void)
{
	char temp_value = '\0';
	printf ("Use Code (R, C, I)? ");
	scanf (" %c", &temp_value);
	return temp_value;
}

int prompt_consumption (char string[])
{
	int temp_value = 0;
	printf ("%s? ", string);
	scanf ("%d", &temp_value);
	return temp_value;
}

double determine_amount_due (char use_code, int consumption1, int consumption2)
{
	double amount_due = 0.0;
	switch (use_code)
	{
		case ('R'):
		case ('r'):
			amount_due = residential_calculation (consumption1);
			break;
		case ('C'):
		case ('c'):
			amount_due = commercial_calculation (consumption1);
			break;
		case ('i'):
		case ('I'):
			amount_due = industrial_calculation (consumption1, consumption2);
			break;
		default:
			break;
	}
	return amount_due;
}

double residential_calculation (int consumption)
{
	double amount_due = 0.0;
	amount_due = 6.0 + (consumption * 0.052);
	return amount_due;
}

double commercial_calculation (int consumption)
{
	double amount_due = 0.0;
	consumption -= 1000;
	amount_due = 60.0;
	if (consumption > 0)
	{
		amount_due += consumption * 0.045;
	}
	return amount_due;
}

double industrial_calculation (int consumption_peak, int consumption_off)
{
	double amount_due = 0.0;
	if (consumption_peak > 0)
	{
		consumption_peak -= 1000;
		amount_due = 76.00;
		if (consumption_peak > 0)
		{
			amount_due += consumption_peak * 0.065;
		}
	}
	if (consumption_off > 0)
	{
		consumption_off -= 1000;
		amount_due = 40.00;
		if (consumption_off > 0)
		{
			amount_due += consumption_off * 0.028;
		}
	}
	return amount_due;
}

void display_amount_due (int account_number, double amount_due)
{
	printf ("Amount due for user %d is: $%lf\n", account_number, amount_due);0
}
