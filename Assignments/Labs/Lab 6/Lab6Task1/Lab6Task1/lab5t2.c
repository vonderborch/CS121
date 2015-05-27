#include "lab5.h"
#include "lab5t2.h"

int task2_main (void)
{
	FILE *infile = NULL;
	int employee_number = 0, total_employees = 0, hours_worked = 0;
	double hour_wages = 0.0, taxes = 0.03625, employee_pay = 0.0,
		total_payroll = 0.0, average_paid = 0.0;

	infile = fopen ("weeklypay.dat", "r");

	while (!feof (infile))
	{
		total_employees++;
		fscanf (infile, "%d", &employee_number);
		fscanf (infile, "%lf", &hour_wages);
		fscanf (infile, "%d", &hours_worked);
		if (hours_worked <= 40)
		{
			employee_pay = (hours_worked * hour_wages);
		}
		else
		{
			employee_pay = ((40 * hour_wages) + 
				((hours_worked - 40) * (hour_wages * 1.5)));
		}
		total_payroll += employee_pay;
		employee_pay = employee_pay - (employee_pay * taxes);
		printf ("Employee #%d Net Pay: $%lf\n", employee_number, employee_pay);
	}
	average_paid = total_payroll / (double)total_employees;
	printf ("\nTotal Employees: %d\nTotal Payroll: $%lf\nAverage Pay: $%lf\n", total_employees, 
		total_payroll, average_paid);
}