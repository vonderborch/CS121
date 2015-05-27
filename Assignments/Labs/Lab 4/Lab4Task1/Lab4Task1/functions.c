
#include "lab4t1.h"


int teacher_main (double purchases, FILE *outfile)
{
	double discount_percent = 0.1, discount_money = 0.0, discount_total = 0.0, sales_tax = 0.0, total = 0.0;
	
	print_receipt (outfile, "Total Purchases = ", purchases);

	// look at discount
	discount_percent = determine_discount (purchases);
	discount_money = calculate_discount (purchases, discount_percent);
	discount_total = calculate_discount_total (purchases, discount_money);
	// Print discount to receipt
	if (discount_percent == 0.1)
	{
		print_receipt (outfile, "Teachers Discount (10%) = ", discount_money);
		print_receipt (outfile, "Discounted Total = ", discount_total);
	}
	else
	{
		print_receipt (outfile, "Teachers Discount (12%) = ", discount_money);
		print_receipt (outfile, "Discounted Total = ", discount_total);
	}

	// calculate sales tax and print to receipt
	sales_tax = calculate_sales_tax (discount_total);
	print_receipt (outfile, "Sales Tax (5%) = ", sales_tax);

	// calculate total and print to receipt
	total = calculate_total (discount_total, sales_tax);
	print_receipt (outfile, "Total = ", total);
	
	// teacher receipt created!
	return 0;
}

int normal_main (double purchases, FILE *outfile)
{
	double sales_tax = 0.0, total = 0.0;

	print_receipt (outfile, "Total Purchases = ", purchases);

	// calculate sales tax and print to receipt
	sales_tax = calculate_sales_tax (purchases);
	print_receipt (outfile, "Sales Tax (5%) = ", sales_tax);

	// calculate total and print to receipt
	total = calculate_total (purchases, sales_tax);
	print_receipt (outfile, "Total = ", total);

	// Normal receipt created!
	return 0;
}

double int_input (void)
{
	int temp_value = 0;
	scanf(" %d", &temp_value);
	return temp_value;
}

double double_input (void)
{
	double temp_value = 0.0;
	scanf(" %lf", &temp_value);
	return temp_value;
}

double purchases_input (void)
{
	double purchases = 0.0;
	printf ("Total Purchase Price? ");
	purchases = double_input ();
	return purchases;
}

int teacher_input (void)
{
	int teacher = 0;
	printf ("Is Teacher (1 = Teacher, 0 = Not Teacher)?");
	teacher = int_input();
	return teacher;
}

double determine_discount (double cost)
{
	double discount = 0.1;
	if (cost >= 100)
	{
		discount = 0.12;
	}
	return discount;
}

double calculate_discount (double purchases, double discount)
{
	double discount_money = purchases * discount;
	return discount_money;
}

double calculate_discount_total (double purchases, double discount)
{
	double discount_total = purchases - discount;
	return discount_total;
}

double calculate_sales_tax (double purchases)
{
	double sales_tax = purchases * 0.05;
	return sales_tax;
}

double calculate_total (double purchases, double sales_tax)
{
	double total = purchases + sales_tax;
	return total;
}

void print_receipt (FILE *outfile, char header[], double number)
{
	fprintf (outfile, "%s%.2lf\n", header, number);
	return;
}
