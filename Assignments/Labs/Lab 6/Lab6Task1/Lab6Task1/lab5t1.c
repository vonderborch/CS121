#include "lab5.h"
#include "lab5t1.h"

int task1_main (void)
{
	FILE *infile = NULL;
	int current_number = 0, sum = 0, is_prime = 0, is_prime_temp = 0, checking = 1;
	double max_check = 0.0;

	infile = fopen ("task1input.txt", "r");

	while (!feof (infile))
	{
		is_prime = 1;
		is_prime_temp = 0;
		checking = 1;
		fscanf (infile, "%d", &current_number);
		max_check = sqrt(current_number);
		sum += current_number;
		printf ("Checking Number %d for Primalty...", current_number);
		while (checking <= max_check)
		{
			checking++;
			is_prime_temp = current_number % checking;
			if (is_prime_temp == 0)
			{
				is_prime = 0;
				checking = max_check + 1;
			}
		}
		if (is_prime == 1)
		{
			printf ("Number %d is a Prime Number.\n", current_number);
		}
		else
		{
			printf ("Number %d is not a Prime Number.\n", current_number);
		}
	}
	is_prime = 1;
	is_prime_temp = 0;
	checking = 1;
	max_check = sqrt(sum);
	while (checking <= max_check)
	{
		checking++;
		is_prime_temp = sum % checking;
		if (is_prime_temp == 0)
		{
			is_prime = 0;
			checking = max_check + 1;
		}
	}
	if (is_prime == 1)
	{
		printf ("The Sum (%d) is a Prime Number.\n", sum);
	}
	else
	{
		printf ("The Sum (%d) is not a Prime Number.\n", sum);
	}
}


int read_integer (FILE *infile)
{
	// Declare a temporary value and set to 0
	int temp_value = 0;
	// Read the temporary value from the passed file
	fscanf (infile, " %d", &temp_value);
	// Return the temporary value
	return temp_value;
}