
#include "pa4t3.h"

int main (void)
{
	FILE *infile = NULL, *receipt = NULL;
	int weekday_minutes = 0, night_minutes = 0, weekend_minutes = 0, total_minutes = 0;
	double monthly_bill = 0.0, average_minute_cost = 0.0, taxes = 0.0, total_bill = 0.0;

	// open files
	infile = fopen ("input.dat", "r");
	receipt = fopen ("receipt.dat", "w");

	// read minutes
	weekday_minutes = read_number (infile);
	night_minutes = read_number (infile);
	weekend_minutes = read_number (infile);

	// calculate total minutes
	total_minutes = calculate_total_minutes (weekday_minutes, night_minutes, weekend_minutes);

	// calculate pre-tax bill
	monthly_bill = calculate_monthly_bill (weekday_minutes, night_minutes, weekend_minutes);
	
	// calculate average minute cost
	average_minute_cost = calculate_average_minute (monthly_bill, total_minutes);

	// calculate tax cost
	taxes = calculate_taxes (monthly_bill);
	
	// calculate total bill
	total_bill = calculate_final_bill (monthly_bill, taxes);

	// print receipt
	print_value (receipt, "Weekday Minutes: ", weekday_minutes);
	print_value (receipt, "Night Minutes: ", night_minutes);
	print_value (receipt, "Weekend Minutes: ", weekend_minutes);
	print_value (receipt, "Total Minutes: ", total_minutes);
	print_double (receipt, "Pre-tax Bill: ", monthly_bill);
	print_double (receipt, "Average Cost per Minute: ", average_minute_cost);
	print_double (receipt, "Taxes (5.25%): ", taxes);
	print_double (receipt, "Total: ", total_bill);

	// cleanup/close program
	fclose(infile);
	fclose(receipt);
	return 0;
}
