#include "labfinal.h"

int main (void)
{
	FILE *input, *output;
	// Input/Output arrays are declared within the Records struct...
			// the inner arrays are of Person-struct type, which
			// contains the last name, first name, and age of a person
	Records baseRecords, updatedRecords;

	printf ("Opening input file...");

	input = fopen ("input.dat", "r");
	if (input == NULL)
	{
		printf ("No input data found! Please create an input file (input.dat)!\n");
	}
	else
	{
		printf ("Input file opened!\n");

		printf ("Getting records...");
		baseRecords = getRecords (input);
		printf ("Records gotten!\n");

		printf ("Sorting records...");
		updatedRecords = sortRecords (baseRecords);
		printf ("Records sorted!\n");

		printf ("Saving sorted records...");
		output = fopen ("output.dat", "w");
		saveRecords (output, updatedRecords);
		printf ("Records saved!\n");

		printf ("Closing input and output files...");
		fclose (input);
		fclose (output);
		printf ("Files closed!\n");
	}

	printf ("Program complete.\n");
	return 0;
}