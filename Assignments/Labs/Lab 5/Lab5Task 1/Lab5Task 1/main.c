#include "lab5t1.h"

int main (void)
{
	char use_code = '\0';
	int correct_code = 1;
	int account_number = 0, consumption_1 = 0, consumption_2 = 0;
	double amount_due = 0.0;

	display_message (1);

	account_number = prompt_account_number ();
	do
	{
		use_code = prompt_use_code ();
		switch (use_code)
		{
			case ('R'):
			case ('r'):
			case ('C'):
			case ('c'):
				consumption_1 = prompt_consumption ("Consumption");
				amount_due = determine_amount_due (use_code, consumption_1, -1);
				break;
			case ('i'):
			case ('I'):
				consumption_1 = prompt_consumption ("Peak Consumption");
				consumption_2 = prompt_consumption ("Off-Peak Consumption");
				amount_due = determine_amount_due (use_code, consumption_1, consumption_2);
				break;
			default:
				correct_code = 0;
				display_message (2);
				break;
		}
	} while (correct_code == 0);
	
	display_amount_due (account_number, amount_due);

	return 0;
}