#include "lab5t2.h"

int main (void)
{
	FILE *infile = NULL, *outfile = NULL;
	char file_name[FILE_NAME_SIZE];
	int file_exists = 0, number_values = 0;
	double value_sum = 0.0, value_average = 0.0;

	///*
	printf ("Enter file name: ");
	scanf (" %s", &file_name);
		infile = open_file_read (file_name);
		file_exists = check_file_exists (infile);
	//*/
	/*
	do
	{
		file_name = get_file_name ();
		infile = open_file_read (file_name);
		file_exists = check_file_exists (infile);
	} while (file_exists == 0);
	*/
	
	outfile = open_file_write ("output.dat");

	while (!feof (infile))
	{
		double value = 0.0;
		value = read_double (infile);
		value_sum += value;
		number_values++;
	}

	value_average = calculate_average_value (number_values, value_sum);

	print_output_double (outfile, "Average Value: ", value_average);

	fclose (infile);
	fclose (outfile);
	return 0;
}