#include <stdio.h>

int calculator (double operand1, double operand2, char operator1);

int main (void)
{
	double operand1 = 0.0, operand2 = 0.0;
	char operator1 = '\0';
	double result1 = 0.0;
	int valid = 1, newcalculation = 1;

	printf ("Please enter an arithmetic expression: ");
	scanf ("%lf %c%lf", &operand1, &operator1, &operand2);

	repeat (newcalculation == 1)
	{
		if (operator1 == '/' && operand2 == 0)
		{
		}
	}
	switch (operator1)
	{
		case '+': 
			result1 = calculator(operand1, operand2, operator1);
			break;
		case '-': 
			result1 = calculator(operand1, operand2, operator1);
			break;
		case '*': 
			result1 = calculator(operand1, operand2, operator1);
			break;
		case '/': 
			if (operand2 == 0)
			{
				valid = 2;
			}
			else
			{
				result1 = calculator(operand1, operand2, operator1);
			}
			break;
		default: valid = 0;
			break;
	}

	if (valid == 1)
	{
		printf ("%lf %c %lf = %lf", operand1, operator1, operand2, result1);
	}
	else if (valid == 2)
	{
		printf ("Error 1: Cannot divide by 0!");
	}
	else
	{
		printf ("Error 2: Invalid operator!");
	}
	printf ("\n\n");

	return 0;
}


int calculator (double operand1, double operand2, char operator1)
{
	double result1 = 0.0;
	switch (operator1)
	{
		case '+': 
			result1 = operand1 + operand2;
			break;
		case '-': 
			result1 = operand1 - operand2;
			break;
		case '*': 
			result1 = operand1 * operand2;
			break;
		case '/': 
			result1 = operand1 / operand2;
			break;
		default: result1 = 0;
			break;
	}
	return result1;
}